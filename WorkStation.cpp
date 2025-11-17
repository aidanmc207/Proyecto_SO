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
    // Primera vez: arrancar thread
    if (!m_thread.isRunning()) {
        m_running = true;
        m_paused  = false;

        emit log(m_name + ": start()");
        m_thread.start();
        return;
    }

    //Reanudar tras pausa
    m_running = true;
    m_paused  = false;
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
            while (m_paused && m_running)
                m_pauseCond.wait(&m_pauseMutex);
        }

        if (!m_running)
            break;

        if (!m_input) {
            QThread::msleep(10);
            continue;
        }

        // Tomar producto de entrada

        Product p = m_input->pop();

        //Si se presiono STOP justo después del pop
        if (!m_running) {
            m_input->push(p); // lo devolvemos
            continue;
        }

        // Procesar
        process(p);
        incrementCount();

        // Enviar a siguiente estación si la hay
        if (m_output){
            m_output->push(p);
        }

        // Notificar que consumió uno
        emit consumed(m_name);

         barSize=processedCount() % 100;

        // Actualizar GUI
        emit stationUpdated(m_name, stateString(), barSize);
        emit statsUpdated(m_name, processedCount(), barSize, reworkCount());

    }
    int finalBarSize = 0;
    if (m_output) {
        finalBarSize++;
    } else if (m_input) {
        finalBarSize = m_input->size();
    }

    emit log(m_name + " loop finished");
    emit stationUpdated(m_name, "Stopped", finalBarSize);
}
