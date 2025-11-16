#include "WorkStation.h"
#include <QMetaObject>
#include <QDebug>
#include <QThread>

WorkStation::WorkStation(const QString& name, QObject* parent)
    : QObject(parent)
    , m_name(name)
{
    // Este objeto vivirá en el hilo m_thread
    this->moveToThread(&m_thread);

    QObject::connect(&m_thread, &QThread::started,
                     this,       &WorkStation::runLoop);
}

WorkStation::~WorkStation()
{
    stop();
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
    if (!m_running) return QStringLiteral("Stopped");
    if (m_paused)   return QStringLiteral("Paused");
    return QStringLiteral("Running");
}

void WorkStation::start()
{
    if (m_running) return;

    m_running = true;
    m_paused  = false;

    emit log(m_name + QStringLiteral(": start()"));
    emit stationUpdated(m_name, stateString(),
                        m_input ? m_input->size() : 0);

    if (!m_thread.isRunning())
        m_thread.start();
}

void WorkStation::pause()
{
    if (!m_running) return;
    m_paused = true;
    emit log(m_name + QStringLiteral(": pause()"));
    emit stationUpdated(m_name, stateString(),
                        m_input ? m_input->size() : 0);
}

void WorkStation::stop()
{
    if (!m_running) return;

    m_running = false;
    m_paused  = false;

    m_pauseCond.wakeAll();   // por si está esperando en pausa

    emit log(m_name + QStringLiteral(": stop()"));
    emit stationUpdated(m_name, QStringLiteral("Stopped"),
                        m_input ? m_input->size() : 0);
}

void WorkStation::runLoop()
{
    emit log(m_name + QStringLiteral(" runLoop started"));
    emit stationUpdated(m_name, stateString(),
                        m_input ? m_input->size() : 0);

    while (m_running)
    {
        // Manejo de pausa
        {
            QMutexLocker locker(&m_pauseMutex);
            while (m_paused && m_running)
                m_pauseCond.wait(&m_pauseMutex);
        }
        if (!m_running)
            break;

        if (!m_input) {
            emit log(m_name + QStringLiteral(" waiting for input buffer (m_input == nullptr)"));
            QThread::msleep(50);
            continue;
        }

        emit log(m_name + QStringLiteral(" calling pop() on input buffer"));
        Product p = m_input->pop();
        emit log(m_name + QStringLiteral(" got product ") + p.show());

        // ---------- SENTINELA: fin de producción ----------
        if (p.isStopSignal) {
            emit log(m_name + QStringLiteral(" received stop signal"));
            // Lo propagamos a la siguiente estación si existe
            if (m_output) {
                emit log(m_name + QStringLiteral(" forwarding stop signal to next station"));
                m_output->push(p);
            }
            break; // salimos del while -> hilo termina limpiamente
        }
        // --------------------------------------------------

        // Procesamiento normal
        process(p);

        if (m_output) {
            emit log(m_name + QStringLiteral(" pushing to output buffer"));
            m_output->push(p);
        } else {
            emit log(m_name + QStringLiteral(" finished product (no output buffer)"));
        }

        emit stationUpdated(m_name, stateString(),
                            m_input ? m_input->size() : 0);
    }

    emit log(m_name + QStringLiteral(" loop finished"));
    emit stationUpdated(m_name, QStringLiteral("Stopped"),
                        m_input ? m_input->size() : 0);
}
