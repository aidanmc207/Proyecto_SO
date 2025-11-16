#pragma once

#include <QObject>
#include <QList>

#include "Buffer.h"
#include "Product.h"
#include "WorkStation.h"

class ProductionLine : public QObject
{
    Q_OBJECT
public:
    explicit ProductionLine(QObject* parent = nullptr);
    ~ProductionLine();

    void addStation(WorkStation* station);
    void link(WorkStation* from, WorkStation* to);   // opcional si quieres enlaces manuales

    Buffer<Product>* firstBuffer() { return &m_entryBuffer; }

public slots:
    void start();
    void pause();
    void stop();

signals:
    void stationUpdated(const QString& name, const QString& state, int queueSize);
    void log(const QString& line);

private:
    QList<WorkStation*> m_stations;
    QList<Buffer<Product>*> m_internalBuffers;
    Buffer<Product> m_entryBuffer;   // entrada a la primera estación

    void autoLinkStations();         // enlaza secuencialmente
};
