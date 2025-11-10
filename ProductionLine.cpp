#include "ProductionLine.h"
#include <QMetaObject>

ProductionLine::ProductionLine(QObject* parent) : QObject(parent) {}
ProductionLine::~ProductionLine() {
    stop();
    for (auto* s : m_stations) s->deleteLater();
}

void ProductionLine::addStation(WorkStation* st) {
    connect(st, &WorkStation::updated, this, &ProductionLine::stationUpdated);
    connect(st, &WorkStation::log,     this, &ProductionLine::log);

    m_stations.push_back(st);

    if (m_buffers.empty()) {
        m_buffers.push_back(std::make_unique<Buffer<Product>>(32));  // buffer de entrada global
    }
    m_buffers.push_back(std::make_unique<Buffer<Product>>(32));      // buffer de salida de esta estación

    const std::size_t idx = static_cast<std::size_t>(m_stations.size() - 1);
    st->setBuffers(m_buffers[idx].get(), m_buffers[idx + 1].get());
}

void ProductionLine::start() {
    for (auto* s : m_stations) {
        s->launch();                                    // <-- arranca QThread ya
        QMetaObject::invokeMethod(s, "start");          // ahora sí, la cola se procesa
    }
}
void ProductionLine::pause(){
    for (auto* s : m_stations) QMetaObject::invokeMethod(s, "pause");
}
void ProductionLine::stop() {
    for (auto* s : m_stations) QMetaObject::invokeMethod(s, "stop");
}
