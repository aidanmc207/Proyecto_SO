#include "Assembler.h"
#include <QThread>

Assembler::Assembler(const QString& name)
    : WorkStation(name)
{
}


void Assembler::process(Product& p)
{
    if (p.state == ProductState::Rework) {
        emit log(name() + ": reworking " + p.show());
        p.state = ProductState::New;
    }

    QThread::msleep(ASSEMBLER_MILIS);
    p.advance();
}
