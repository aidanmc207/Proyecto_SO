#include "ProductionLine.h"
#include <QMetaObject>

ProductionLine::ProductionLine(QObject* parent)
    : QObject(parent)
    , m_entryBuffer(64)
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

    connect(station, &WorkStation::log,
            this,    &ProductionLine::log);

    connect(station, &WorkStation::stationUpdated,
            this,    &ProductionLine::stationUpdated);

    autoLinkStations();
}

void ProductionLine::autoLinkStations()
{
    if (m_stations.isEmpty())
        return;

    // Primera estación desde entryBuffer
    m_stations.first()->setInputBuffer(&m_entryBuffer);

    // Buffers intermedios
    for (int i = 0; i < m_stations.size() - 1; ++i) {
        WorkStation* from = m_stations[i];
        WorkStation* to   = m_stations[i + 1];

        Buffer<Product>* buf = nullptr;
        if (i < m_internalBuffers.size())
            buf = m_internalBuffers[i];
        else {
            buf = new Buffer<Product>(64);
            m_internalBuffers.append(buf);
        }

        from->setOutputBuffer(buf);
        to->setInputBuffer(buf);
    }

    // Última estación sin output
    m_stations.last()->setOutputBuffer(nullptr);
}

void ProductionLine::start()
{
    emit log("ProductionLine: start()");
    for (auto* st : std::as_const(m_stations)) {
        if (st)
            st->start();
    }
}


void ProductionLine::pause()
{
    emit log("ProductionLine: pause()");
    for (auto* st : std::as_const(m_stations)) {
        if (st)
            st->pause();
    }
}


void ProductionLine::stop()
{
    emit log("ProductionLine: stop()");
    for (auto* st : std::as_const(m_stations)) {
        if (st)
            st->stop();
    }
}


