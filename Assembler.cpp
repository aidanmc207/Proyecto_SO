#include "Assembler.h"
#include <QThread>

Assembler::Assembler(const QString& name, QObject* parent)
    : WorkStation(name, parent)
{
}

void Assembler::process(Product& p)
{
    QThread::msleep(200);
    p.advance();
}
