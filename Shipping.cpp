#include "Shipping.h"
#include <QThread>

Shipping::Shipping(const QString& name)
    : WorkStation(name)
{
}

void Shipping::process(Product& p)
{
    // Simular el proceso de envío
    QThread::msleep(Config::shipDelay); // Tiempo de envío

    p.shipped = true;

    emit log(QString("%1 shipped %2").arg(name(), p.show()));
}
