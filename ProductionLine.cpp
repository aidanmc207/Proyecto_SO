#include "ProductionLine.h"
#include <QMetaObject>

ProductionLine::ProductionLine(QObject* parent)
    : QObject(parent)
    , m_entryBuffer(64)      // capacidad de entrada
{
}

ProductionLine::~ProductionLine()
{
    stop();
    qDeleteAll(m_internalBuffers);
    m_internalBuffers.clear();
}

void ProductionLine::addStation(WorkStation* station)
{
    if (!station) return;

    m_stations.append(station);

    // Reenvía logs y estados hacia afuera
    connect(station, &WorkStation::log,
            this,    &ProductionLine::log);

    connect(station, &WorkStation::stationUpdated,
            this,    &ProductionLine::stationUpdated);

    // Cada vez que agregas una estación, rehace los enlaces
    autoLinkStations();
}

void ProductionLine::autoLinkStations()
{
    if (m_stations.isEmpty())
        return;

    // La primera estación siempre lee de m_entryBuffer
    m_stations.first()->setInputBuffer(&m_entryBuffer);

    // Crear/enlazar buffers intermedios entre estaciones
    for (int i = 0; i < m_stations.size() - 1; ++i) {
        WorkStation* from = m_stations[i];
        WorkStation* to   = m_stations[i + 1];

        Buffer<Product>* buf = nullptr;

        if (i < m_internalBuffers.size()) {
            buf = m_internalBuffers[i];
        } else {
            buf = new Buffer<Product>(64);
            m_internalBuffers.append(buf);
        }

        from->setOutputBuffer(buf);
        to->setInputBuffer(buf);
    }

    // La última estación no necesita output (producto final)
    if (!m_stations.isEmpty())
        m_stations.last()->setOutputBuffer(nullptr);
}

void ProductionLine::link(WorkStation* from, WorkStation* to)
{
    // Solo si quieres enlaces manuales extras
    if (!from || !to) return;

    auto* buf = new Buffer<Product>(64);
    m_internalBuffers.append(buf);
    from->setOutputBuffer(buf);
    to->setInputBuffer(buf);
}

void ProductionLine::start()
{
    emit log("ProductionLine: start()");
    for (auto* st : std::as_const(m_stations)) {
        QMetaObject::invokeMethod(st, "start", Qt::QueuedConnection);
    }
}

void ProductionLine::pause()
{
    emit log("ProductionLine: pause()");
    for (auto* st : std::as_const(m_stations)) {
        QMetaObject::invokeMethod(st, "pause", Qt::QueuedConnection);
    }
}

void ProductionLine::stop()
{
    emit log("ProductionLine: stop()");
    for (auto* st : std::as_const(m_stations)) {
        QMetaObject::invokeMethod(st, "stop", Qt::QueuedConnection);
    }
}
