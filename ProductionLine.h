#pragma once
#include <QObject>
#include <QVector>
#include <memory>
#include <vector>              // <<< añade esto
#include "WorkStation.h"
#include "Buffer.h"
#include "Product.h"

class ProductionLine : public QObject {
    Q_OBJECT
public:
    explicit ProductionLine(QObject* parent=nullptr);
    ~ProductionLine();

    void addStation(WorkStation* st);
    void start();
    void pause();
    void stop();

    Buffer<Product>* firstBuffer() { return m_buffers.front().get(); } // ok con std::vector

signals:
    void stationUpdated(const QString&, const QString&, int);
    void log(const QString&);

private:
    QVector<WorkStation*> m_stations;                          // puede quedarse en QVector
    std::vector<std::unique_ptr<Buffer<Product>>> m_buffers;   // <<< cambia a std::vector
};
