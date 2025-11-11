#pragma once
#include "WorkStation.h"
#include <QThread>

class Packer : public WorkStation {
    Q_OBJECT
public:
    explicit Packer(const QString& name, QObject* parent=nullptr)
        : WorkStation(name, parent) {}
protected:
    void process(Product& p) override { QThread::msleep(120); p.advance(); }
};
