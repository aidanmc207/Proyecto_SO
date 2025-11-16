#include "CleanUpService.h"

CleanUpService::CleanUpService(QObject* parent)
    : QObject(parent)
{
}

void CleanUpService::resetAll()
{
    emit info("Cleanup: resetting all resources");
}
