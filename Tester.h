#pragma once
#include "WorkStation.h"
#include <QThread>

class Tester : public WorkStation {
    Q_OBJECT
public:
    explicit Tester(const QString& name, QObject* parent=nullptr)
        : WorkStation(name, parent) {}
protected:
    void process(Product& p) override { QThread::msleep(150); p.advance(); }
};
