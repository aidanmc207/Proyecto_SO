#include "StatsMonitor.h"

StatsMonitor::StatsMonitor(QObject* parent)
    : QObject(parent)
{
}

void StatsMonitor::recordStats(long totalProcessed, int totalInQueue, long totalRework)
{
    m_currentTime += 1.0; // Incrementar en 1 segundo

    m_timestamps.append(m_currentTime);
    m_totalProcessed.append(static_cast<double>(totalProcessed));
    m_totalInQueue.append(static_cast<double>(totalInQueue));
    m_totalRework.append(static_cast<double>(totalRework));

    // Mantener solo los últimos MAX_POINTS puntos
    if (m_timestamps.size() > MAX_POINTS) {
        m_timestamps.removeFirst();
        m_totalProcessed.removeFirst();
        m_totalInQueue.removeFirst();
        m_totalRework.removeFirst();
    }

    emit dataUpdated();
}

void StatsMonitor::recordStationData(const QString& station, long processed)
{
    if (!m_stationData.contains(station)) {
        m_stationData[station] = QVector<double>();
    }

    m_stationData[station].append(static_cast<double>(processed));

    // Mantener solo los últimos MAX_POINTS puntos
    if (m_stationData[station].size() > MAX_POINTS) {
        m_stationData[station].removeFirst();
    }
}

QVector<double> StatsMonitor::getStationData(const QString& station) const
{
    return m_stationData.value(station, QVector<double>());
}

void StatsMonitor::reset()
{
    m_timestamps.clear();
    m_totalProcessed.clear();
    m_totalInQueue.clear();
    m_totalRework.clear();
    m_stationData.clear();
    m_currentTime = 0.0;

    emit dataUpdated();
}
