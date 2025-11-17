#pragma once
#include "WorkStation.h"
#include <QThread>
#include "config.h"


class Shipping : public WorkStation
{
    Q_OBJECT
public:
    explicit Shipping(const QString& name);

protected:
    void process(Product& p) override;
};
