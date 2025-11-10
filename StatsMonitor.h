#pragma once
#include <QObject>

class StatsMonitor : public QObject {
    Q_OBJECT
public:
    explicit StatsMonitor(QObject* parent=nullptr);
signals:
    void throughputUpdated(double value);
};
