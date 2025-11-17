#include "ProductionController.h"

ProductionController::ProductionController(QObject* parent)
    : QObject(parent)
    , persistence(new Persistence(this))
    , m_statsMonitor(new StatsMonitor(this))
{
    // Crear la línea de producción
    m_line = new ProductionLine(this);

    // Crear las 6 estaciones que necesitamos
    auto* asmbl1 = new Assembler("Assembler-1");
    auto* asmbl2 = new Assembler("Assembler-2");
    auto* test   = new Tester("Tester");
    auto* qc     = new QualityControl("QualityControl");
    auto* pack   = new Packer("Packer");
    auto* ship   = new Shipping("Shipping");

    m_line->addStation(asmbl1);
    m_line->addStation(asmbl2);
    m_line->addStation(test);
    m_line->addStation(qc);
    m_line->addStation(pack);
    m_line->addStation(ship);

    // Buffer compartido donde ambos ensambladores ponen sus productos
    // para que el Tester los tome (un solo buffer para los dos)
    m_bufAsmToTest = new Buffer<Product>(128);

    // Buffers de entrada separados para cada ensamblador
    m_entry1 = new Buffer<Product>(128);
    m_entry2 = new Buffer<Product>(128);

    // Conectar buffers a cada ensamblador
    asmbl1->setInputBuffer(m_entry1);
    asmbl2->setInputBuffer(m_entry2);

    asmbl1->setOutputBuffer(m_bufAsmToTest);
    asmbl2->setOutputBuffer(m_bufAsmToTest);

    test->setInputBuffer(m_bufAsmToTest);

    // Configurar el pipe para productos que fallan

    m_pipeManager = new PipeManager(m_line->entryBuffer(), this);
    qc->setPipeManager(m_pipeManager);

    connect(m_pipeManager, &PipeManager::log,
            this, &ProductionController::logLine);

    // Cuando un ensamblador consume un producto, generamos uno nuevo
    // Esto es para producción "just in time" (no generar de más)
    connect(asmbl1, &WorkStation::consumed,
            this, &ProductionController::onStationConsumed);
    connect(asmbl2, &WorkStation::consumed,
            this, &ProductionController::onStationConsumed);

    // Conectar logs y actualizaciones de la línea con el controller
    connect(m_line, &ProductionLine::log,
            this,   &ProductionController::logLine);

    connect(m_line, &ProductionLine::stationUpdated,
            this,   &ProductionController::stationUpdated);

    // Conectar estadísticas de cada estación para mostrarlas en la GUI
    for (auto* st : m_line->stations())
    {
        connect(st, &WorkStation::statsUpdated,
                this, &ProductionController::statsUpdated);
    }

    // Intentar cargar estado anterior si existe
    long savedId;
    if (persistence->loadState(m_line, savedId))
    {
        nextProductId = savedId;
        emit logLine("Previous state loaded successfully.");
    }
    else {
        nextProductId = 1;
        emit logLine("No previous state found.");
    }

    // Crear los hilos de mantenimiento (GeneralClean, GeneralLogs, GeneralStats)
    maintenance = new ThreadManager(m_line, this);
    maintenance->setStatsMonitor(m_statsMonitor);

    // Hacer que todos los logs pasen por el ThreadManager
    // para que los guarde en el archivo runtime.log
    connect(m_line, &ProductionLine::log,
            maintenance, &ThreadManager::pushLog);

    connect(this, &ProductionController::logLine,
            maintenance, &ThreadManager::pushLog);
    //Conecto al log win
    connect(maintenance, &ThreadManager::log,
            logWin, &LogWindow::appendLog,
            Qt::QueuedConnection);


    // Iniciar los hilos de mantenimiento
    maintenance->startAll();

}
void ProductionController::setLogWindow(LogWindow* win)
{
    logWin = win;

    if (!m_line || !logWin)
        return;

    // Conectar TODAS las estaciones al LogWindow
    for (auto* ws : m_line->stations()) {
        connect(ws, &WorkStation::log,
                logWin, &LogWindow::appendLog);
    }
}

void ProductionController::start()
{
    if (!m_running) {
        m_running = true;
        m_paused  = false;

        m_line->start();
        maintenance->startAll(); // Reiniciar los hilos de mantenimiento
        generateProduct(); // primer producto

        emit logLine("Controller: start()");
        return;
    }

    if (m_paused) {
        m_paused = false;
        m_line->start();
        emit logLine("Controller: resume()");
        return;
    }

    emit logLine("Controller: start() ignored (already running)");
}

void ProductionController::pause()
{
    if (!m_running || m_paused)
        return;

    m_paused = true;
    m_line->pause();

    emit logLine("Controller: pause()");
}

void ProductionController::stop()
{
    if (!m_running)
        return;

    m_running = false;
    m_paused  = false;

    m_line->stop();
    maintenance->stopAll();

    // Resetear contadores de todas las estaciones cuando se detiene
    for (auto* st : m_line->stations()) {
        if (st) {
            st->resetCount();
        }
    }

    // Resetear el StatsMonitor para reiniciar el gráfico
    if (m_statsMonitor) {
        m_statsMonitor->reset();
    }

    emit logLine("Controller: stop() - Contadores y gráfico reseteados");
}

void ProductionController::generateProduct()
{
    if (!m_running) return;

    // Crear un nuevo producto con ID único
    Product p;
    p.id = nextProductId++;
    int idx = QRandomGenerator::global()->bounded(productTypes.size());
    p.type = productTypes[idx];

    // Alternar entre los dos ensambladores (Round-Robin)
    // para balancear la carga entre ambos
    if (!m_toggle)
        m_entry1->push(p);
    else
        m_entry2->push(p);

    m_toggle = !m_toggle;

    emit logLine(QString("Generated %1").arg(p.show()));
}


void ProductionController::onStationConsumed(const QString& stationName)
{
    if (!m_running) return;

    if (stationName.startsWith("Assembler")) {
        generateProduct();
    }
}

void ProductionController::saveState()
{
    persistence->saveState(m_line, nextProductId);
    emit logLine("State saved to file.");
}

// Métodos para control individual de estaciones
void ProductionController::startStation(const QString& stationName)
{
    for (auto* st : m_line->stations()) {
        if (st->name() == stationName ||
            (stationName == "Assembler" && st->name().startsWith("Assembler"))) {

            // Si está stopped, iniciar
            if (!st->isRunning() && !st->isPaused()) {
                st->start();
                emit logLine(QString("%1: started").arg(st->name()));
            }
            // Si está paused, reanudar
            else if (st->isPaused()) {
                st->start(); // start() reanuda si está pausado
                emit logLine(QString("%1: resumed").arg(st->name()));
            }
            else {
                emit logLine(QString("%1: already running").arg(st->name()));
            }
        }
    }
}

void ProductionController::pauseStation(const QString& stationName)
{
    for (auto* st : m_line->stations()) {
        if (st->name() == stationName ||
            (stationName == "Assembler" && st->name().startsWith("Assembler"))) {
            st->pause();
            emit logLine(QString("%1: paused").arg(st->name()));
        }
    }
}

void ProductionController::stopStation(const QString& stationName)
{
    for (auto* st : m_line->stations()) {
        if (st->name() == stationName ||
            (stationName == "Assembler" && st->name().startsWith("Assembler"))) {
            st->stop();
            emit logLine(QString("%1: stopped").arg(st->name()));
        }
    }
}
