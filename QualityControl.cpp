#include "QualityControl.h"
#include "PipeManager.h"
#include <QThread>
#include <QRandomGenerator>

QualityControl::QualityControl(const QString& name)
    : WorkStation(name)
{}

void QualityControl::process(Product& p)
{
    emit log(QString("%1: Inspecting %2").arg(name(), p.show()));

    QThread::msleep(Config::qcDelay);

    bool fail= (QRandomGenerator::global()->bounded(100) < Config::failProb);//probabilidad de fallo
    if (fail)
    {
        emit log(QString("%1: FAILED inspection sending back to Assembly").arg(name()));

        p.state = ProductState::Rework;
        incrementRework();

        if (m_pipe)
            m_pipe->sendToPipe(p);
        else
            emit log("QualityControl: NO PIPE");

        //NO avanzo al siguiente
        return;
    }

    emit log(QString("%1: PASSED inspection").arg(name()));
    p.advance();
}
