#include "ThreadManager.h"

ThreadManager::ThreadManager(QObject* parent)
    : QObject(parent)
{
}

void ThreadManager::registerThread(QThread* t)
{
    if (!t) return;
    QMutexLocker locker(&m_mutex);
    if (!m_threads.contains(t))
        m_threads.append(t);
}

void ThreadManager::stopAll()
{
    QMutexLocker locker(&m_mutex);
    for (QThread* t : std::as_const(m_threads)) {
        if (!t) continue;
        t->quit();
        t->wait();
    }
    m_threads.clear();
    emit log(QStringLiteral("ThreadManager: all threads stopped"));
}
