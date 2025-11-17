#include "ProductionController.h"

ProductionController::ProductionController(QObject* parent)
    : QObject(parent)
    , persistence(new Persistence(this))
{
    // crear línea
    m_line = new ProductionLine(this);

    // estaciones
    auto* asmbl1 = new Assembler("Assembler-1");
    auto* asmbl2 = new Assembler("Assembler-2");
    auto* test   = new Tester("Tester");
    auto* pack   = new Packer("Packer");
    auto* qc = new QualityControl("QualityControl");

    m_line->addStation(asmbl1);
    m_line->addStation(asmbl2);
    m_line->addStation(test);
    m_line->addStation(qc);
    m_line->addStation(pack);

    // buffer compartido entre assemblers y tester
    m_bufAsmToTest = new Buffer<Product>(128);

    Buffer<Product>* entry = m_line->entryBuffer();
    asmbl1->setInputBuffer(entry);
    asmbl2->setInputBuffer(entry);

    asmbl1->setOutputBuffer(m_bufAsmToTest);
    asmbl2->setOutputBuffer(m_bufAsmToTest);

    test->setInputBuffer(m_bufAsmToTest);

    //pipes

    m_pipeManager = new PipeManager(m_line->entryBuffer(), this);
    qc->setPipeManager(m_pipeManager);

    connect(m_pipeManager, &PipeManager::log,
            this, &ProductionController::logLine);

    // signals de consumo para producción "just in time"
    connect(asmbl1, &WorkStation::consumed,
            this, &ProductionController::onStationConsumed);
    connect(asmbl2, &WorkStation::consumed,
            this, &ProductionController::onStationConsumed);

    // log y actualización de estaciones
    connect(m_line, &ProductionLine::log,
            this,   &ProductionController::logLine);

    connect(m_line, &ProductionLine::stationUpdated,
            this,   &ProductionController::stationUpdated);

    // cargar estado previo
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

    // hilos de mantenimiento
    maintenance = new ThreadManager(m_line, this);

    // conectar logs de todas partes a maintenance
    connect(m_line, &ProductionLine::log,
            maintenance, &ThreadManager::pushLog);

    connect(this, &ProductionController::logLine,
            maintenance, &ThreadManager::pushLog);


    maintenance->startAll();

}

void ProductionController::start()
{
    if (!m_running) {
        m_running = true;
        m_paused  = false;

        m_line->start();
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

    emit logLine("Controller: stop()");
}

void ProductionController::generateProduct()
{
    if (!m_running) return;

    Product p;
    p.id = nextProductId++;
    int idx = QRandomGenerator::global()->bounded(productTypes.size());
    p.type = productTypes[idx];

    m_line->entryBuffer()->push(p);

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
