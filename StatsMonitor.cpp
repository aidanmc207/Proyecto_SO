#include "StatsMonitor.h"

StatsMonitor::StatsMonitor(QObject* parent)
    : QObject(parent)
{
}

void StatsMonitor::updateThroughput(double value)
{
    m_series.append(value);
    if (m_series.size() > 1000)        // corta historial si se hace muy grande
        m_series.remove(0, m_series.size() - 1000);

    emit renderSeries(m_series);
}
