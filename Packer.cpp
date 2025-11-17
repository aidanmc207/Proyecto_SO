#include "Packer.h"
#include <QThread>

Packer::Packer(const QString& name): WorkStation(name){}


void Packer::process(Product& p)
{
    QThread::msleep(50);
    p.advance();
}
