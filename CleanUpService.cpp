#include "CleanUpService.h"

CleanUpService::CleanUpService(QObject* parent) : QObject(parent) {}
void CleanUpService::resetAll() { emit info(QStringLiteral("Cleanup executed")); }
