#pragma once
#include "WorkStation.h"
#include <QThread>

class Packer : public WorkStation
{
    Q_OBJECT
public:
    explicit Packer(const QString& name);

protected:
    void process(Product& p) override;
};
