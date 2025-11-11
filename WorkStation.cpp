#include "WorkStation.h"

WorkStation::WorkStation(const QString& name, QObject* parent)
    : QObject(parent), m_name(name)
{
    this->moveToThread(&m_thread);
    QObject::connect(&m_thread, &QThread::started, this, &WorkStation::runLoop);
}

WorkStation::~WorkStation() {
    m_thread.requestInterruption();
    m_thread.quit();
    m_thread.wait();
}

void WorkStation::launch() {
    if (!m_thread.isRunning()) m_thread.start();
}

void WorkStation::start(){ m_running = true; emit log(m_name + ": start()"); }
void WorkStation::pause(){ m_paused = !m_paused; emit log(m_name + (m_paused?": pause()":": resume()")); }
void WorkStation::stop(){ m_running = false; emit log(m_name + ": stop()"); }

void WorkStation::runLoop(){
    emit updated(m_name, "Running", 0);
    while(!QThread::currentThread()->isInterruptionRequested()){
        if(!m_running) { QThread::msleep(60); continue; }
        if(m_paused){ emit updated(m_name, "Paused", 0); QThread::msleep(120); continue; }
        if(!m_in || !m_out){ QThread::msleep(60); continue; }
        Product p = m_in->pop();
        emit updated(m_name, "Processing", 10);
        process(p);
        emit updated(m_name, "Processing", 90);
        m_out->push(p);
        emit updated(m_name, "Idle", 0);
    }
}
