#include "Packer.h"
#include <QThread>

Packer::Packer(const QString& name, QObject* parent)
    : WorkStation(name, parent)
{
}

void Packer::process(Product& p)
{
    QThread::msleep(120);
    p.advance();
}
