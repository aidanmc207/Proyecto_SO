#include "PipeManager.h"

PipeManager::PipeManager(QObject* parent)
    : QObject(parent)
{
}

void PipeManager::transfer(WorkStation* from, WorkStation* to, const Product& p)
{
    emit log(QStringLiteral("Pipe: %1 -> %2")
                 .arg(from->name())
                 .arg(to->name()));
}
