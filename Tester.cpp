#include "Tester.h"
#include <QThread>

Tester::Tester(const QString& name, QObject* parent)
    : WorkStation(name, parent)
{
}

void Tester::process(Product& p)
{
    QThread::msleep(150);
    p.advance();
}
