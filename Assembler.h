#pragma once
#include "WorkStation.h"
#include <QThread>

class Assembler : public WorkStation
{
    Q_OBJECT
public:
    explicit Assembler(const QString& name);

protected:
    void process(Product& p) override;
};
