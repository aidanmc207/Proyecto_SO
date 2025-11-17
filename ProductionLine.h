#pragma once
#include <QObject>
#include <QList>
#include "Buffer.h"
#include "WorkStation.h"
#include "product.h"

class ProductionLine : public QObject
{
    Q_OBJECT
public:
    explicit ProductionLine(QObject* parent = nullptr);
    ~ProductionLine();

    void addStation(WorkStation* st);
    void start();
    void pause();
    void stop();
    Buffer<Product>* firstBuffer() { return &m_entryBuffer; }

    //PERSISTENCIAS

    const Buffer<Product>* entryBuffer() const { return &m_entryBuffer; }
    Buffer<Product>* entryBuffer() { return &m_entryBuffer; }

    const QList<Buffer<Product>*>& internalBuffers() const { return m_internalBuffers; }
    const QList<WorkStation*>& stations() const { return m_stations; }

signals:
    void log(const QString& line);
    void stationUpdated(const QString& name, const QString& state, int queueSize);

private:
    void autoLinkStations();

    QList<WorkStation*> m_stations;
    QList<Buffer<Product>*> m_internalBuffers;

    Buffer<Product> m_entryBuffer;
};
