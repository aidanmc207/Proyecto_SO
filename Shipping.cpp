#include "Shipping.h"
#include <QThread>

Shipping::Shipping(const QString& name)
    : WorkStation(name)
{
}

void Shipping::process(Product& p)
{
    QThread::msleep(SHIPPING_MILIS);
    p.advance();
}
