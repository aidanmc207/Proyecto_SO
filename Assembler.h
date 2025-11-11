#pragma once
#include "WorkStation.h"
#include <QThread>

class Assembler : public WorkStation {
    Q_OBJECT
public:
    explicit Assembler(const QString& name, QObject* parent=nullptr)
        : WorkStation(name, parent) {}
protected:
    void process(Product& p) override { QThread::msleep(200); p.advance(); }
};
