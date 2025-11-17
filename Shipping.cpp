#include "Shipping.h"
#include <QThread>

Shipping::Shipping(const QString& name)
    : WorkStation(name)
{
}

void Shipping::process(Product& p)
{
    QThread::msleep(200);
    p.advance();
}
