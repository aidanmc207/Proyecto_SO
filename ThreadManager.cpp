#include "ThreadManager.h"
#include <QFile>
#include <QDateTime>

ThreadManager::ThreadManager(ProductionLine* line, QObject* parent)
    : QObject(parent)
    , m_line(line)
{
    // cada cierto tiempo limpiamos
    connect(&m_cleanTimer, &QTimer::timeout,
            this, &ThreadManager::doClean);

    // cada cierto tiempo publicamos estadísticas
    connect(&m_statsTimer, &QTimer::timeout,
            this, &ThreadManager::doStats);
}

void ThreadManager::startAll()
{
    // limpieza cada 15 segundos
    m_cleanTimer.start(15000);

    // estadísticas cada 1 segundo
    m_statsTimer.start(1000);

    emit log("ThreadManager: maintenance timers started");
}

void ThreadManager::stopAll()
{
    m_cleanTimer.stop();
    m_statsTimer.stop();
    emit log("ThreadManager: maintenance timers stopped");
}

void ThreadManager::pushLog(const QString& text)
{
    // Escribir a archivo
    QFile f("runtime.log");
    if (f.open(QIODevice::Append))
    {
        QString line = QString("[%1] %2\n")
                           .arg(QDateTime::currentDateTime().toString("hh:mm:ss"),
                                text);
        f.write(line.toUtf8());
    }

    // Reemitimos por si la UI quiere escuchar
    emit log(text);
}

void ThreadManager::doClean()
{
    if (!m_line) return;

    emit log("ThreadManager: GeneralCleanThreads running...");

    // limpiar buffers internos
    for (auto* buf : m_line->internalBuffers()) {
        if (buf) buf->clear();
    }

    // limpiar buffer de entrada
    if (m_line->entryBuffer())
        m_line->entryBuffer()->clear();

    // resetear contadores de estaciones
    for (auto* st : m_line->stations()) {
        if (st) st->resetCount();
    }

    emit log("ThreadManager: cleanup complete.");
}

void ThreadManager::doStats()
{
    if (!m_line) return;

    for (auto* st : m_line->stations())
    {
        if (!st) continue;

        emit statsUpdated(st->name(),
                          st->processedCount(),
                          st->inputBuffer() ? st->inputBuffer()->size() : 0,
                          st->reworkCount());
    }
}
