#pragma once

#include <QObject>
#include <QVector>
#include <QMap>

class StatsMonitor : public QObject
{
    Q_OBJECT
public:
    explicit StatsMonitor(QObject* parent = nullptr);

    // Obtener datos históricos para graficar
    QVector<double> getTimestamps() const { return m_timestamps; }
    QVector<double> getTotalProcessed() const { return m_totalProcessed; }
    QVector<double> getTotalInQueue() const { return m_totalInQueue; }
    QVector<double> getTotalRework() const { return m_totalRework; }

    QVector<double> getStationData(const QString& station) const;

    void reset(); // Resetear todos los datos

public slots:
    void recordStats(long totalProcessed, int totalInQueue, long totalRework);
    void recordStationData(const QString& station, long processed);

signals:
    void dataUpdated(); // Señal para notificar que hay nuevos datos

private:
    QVector<double> m_timestamps;
    QVector<double> m_totalProcessed;
    QVector<double> m_totalInQueue;
    QVector<double> m_totalRework;

    QMap<QString, QVector<double>> m_stationData;

    double m_currentTime = 0.0;
    static constexpr int MAX_POINTS = 60; // Mantener últimos 60 segundos
};
