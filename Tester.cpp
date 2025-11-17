#include "Tester.h"
#include <QThread>

Tester::Tester(const QString& name)
    : WorkStation(name)
{
}


void Tester::process(Product& p)
{
    QThread::msleep(75);
    p.advance();
}
