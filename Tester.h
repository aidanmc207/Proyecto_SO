#pragma once
#include "WorkStation.h"
#include <QThread>
#include "Config.h"

class Tester : public WorkStation
{
    Q_OBJECT
public:
    explicit Tester(const QString& name);

protected:
    void process(Product& p) override;
};
