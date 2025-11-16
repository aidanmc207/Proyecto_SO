#pragma once

#include <QObject>
#include <QVector>

class StatsMonitor : public QObject
{
    Q_OBJECT
public:
    explicit StatsMonitor(QObject* parent = nullptr);

public slots:
    void updateThroughput(double value); // p. ej. productos/segundo

signals:
    void renderSeries(const QVector<double>& series); // para que la UI grafique

private:
    QVector<double> m_series;
};
