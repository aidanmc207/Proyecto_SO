#include "Logger.h"

Logger::Logger(QObject* parent) : QObject(parent) {}
void Logger::emitLine(const QString& s) { emit line(s); }
