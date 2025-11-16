#pragma once

#include <QObject>
#include <QString>
#include "Product.h"
#include "WorkStation.h"

class PipeManager : public QObject
{
    Q_OBJECT
public:
    explicit PipeManager(QObject* parent = nullptr);

    // Mueve producto entre estaciones
    void transfer(WorkStation* from, WorkStation* to, const Product& p);

signals:
    void log(const QString& msg);
};
