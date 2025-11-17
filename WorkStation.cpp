#include "WorkStation.h"
#include <QThread>

WorkStation::WorkStation(const QString& name)
    : QObject(nullptr)
    , m_name(name)
{
    moveToThread(&m_thread);

    connect(&m_thread, &QThread::started,
            this,      &WorkStation::runLoop);
}

WorkStation::~WorkStation()
{
    stop();
    m_thread.requestInterruption();
    m_pauseCond.wakeAll();
    m_thread.quit();
    m_thread.wait();
}

void WorkStation::setInputBuffer(Buffer<Product>* buf)
{
    m_input = buf;
}

void WorkStation::setOutputBuffer(Buffer<Product>* buf)
{
    m_output = buf;
}

QString WorkStation::stateString() const
{
    if (!m_running) return "Stopped";
    if (m_paused)   return "Paused";
    return "Running";
}

void WorkStation::start()
{
    // Primera vez o después de un stop completo: arrancar thread
    if (!m_thread.isRunning()) {
        m_running = true;
        m_paused  = false;
        m_stopped = false;

        emit log(m_name + ": start()");
        m_thread.start();
        return;
    }

    // Reanudar tras pausa o después de stop (pero el thread sigue corriendo)
    m_running = true;
    m_paused  = false;
    m_stopped = false;
    m_pauseCond.wakeAll();
    emit log(m_name + ": resume()");
}

void WorkStation::pause()
{
    if (!m_running) return;
    m_paused = true;
    emit log(m_name + ": pause()");
}

void WorkStation::stop()
{
    if (!m_running && !m_paused) return;

    m_running = false;
    m_paused  = false;
    m_stopped = true;  // Marcar que se hizo stop completo
    m_pauseCond.wakeAll();
    emit log(m_name + ": stop()");
}

void WorkStation::runLoop()
{
    emit log(m_name + " runLoop started");

    while (true)
    {
        // Manejo de pausa/parada
        {
            QMutexLocker locker(&m_pauseMutex);
            while ((m_paused || m_stopped) && !m_thread.isInterruptionRequested())
                m_pauseCond.wait(&m_pauseMutex);
        }

        // Si se solicitó interrupción del thread (destructor), salir
        if (m_thread.isInterruptionRequested())
            break;

        // Si no está corriendo, esperar
        if (!m_running) {
            QThread::msleep(100);
            continue;
        }

        if (!m_input) {
            QThread::msleep(10);
            continue;
        }

        // Tomar producto de entrada
        Product p = m_input->pop();
        if (!m_running) continue;

        // Procesar
        process(p);
        incrementCount();

        // Enviar a siguiente estación si la hay
        if (m_output)
            m_output->push(p);

        // Notificar que consumió uno (para producción "just in time")
        emit consumed(m_name);

        // Actualizar GUI
        emit stationUpdated(m_name,stateString(), m_input ? m_input->size() : 0);
        emit statsUpdated(m_name, processedCount(), m_input ? m_input->size() : 0 ,reworkCount());

    }

    emit log(m_name + " loop finished");
    emit stationUpdated(m_name, "Stopped", m_input ? m_input->size() : 0);
}
