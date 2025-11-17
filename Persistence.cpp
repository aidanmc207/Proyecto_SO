#include "Persistence.h"
#include <QFile>
#include <QJsonDocument>
#include <QDateTime>

Persistence::Persistence(QObject* parent)
    : QObject(parent)
{}

//
// ---------------- PRODUCT <-> JSON ----------------
//

QJsonObject Persistence::productToJson(const Product& p) const {
    QJsonObject o;
    o["id"] = (double)p.id;
    o["type"] = p.type;
    o["state"] = (int)p.state;
    return o;
}

Product Persistence::jsonToProduct(const QJsonObject& obj) const {
    Product p;
    p.id = obj["id"].toInt();
    p.type = obj["type"].toString();
    p.state = (ProductState)obj["state"].toInt();
    return p;
}

//
// ---------------- BUFFER <-> JSON ----------------
//

QJsonArray Persistence::bufferToJson(const Buffer<Product>* buf) const {
    QJsonArray arr;
    QVector<Product> temp = buf->toVector();
    for (auto& p : temp)
        arr.append(productToJson(p));
    return arr;
}

void Persistence::jsonToBuffer(const QJsonArray& arr, Buffer<Product>* buf) const {
    for (auto v : arr)
        buf->push(jsonToProduct(v.toObject()));
}


//Stats
QJsonObject Persistence::stationStatsToJson(const WorkStation* st) const {
    QJsonObject obj;
    obj["processed"] = (double) st->processedCount();
    return obj;
}

void Persistence::jsonToStationStats(const QJsonObject& obj, WorkStation* st) const {
    long val = obj["processed"].toInt();
    for (int i = 0; i < val; i++)
        st->incrementCount();
}
//SAVE
//guardo el estado actual

bool Persistence::saveState(const ProductionLine* line,
                            long nextProductId,
                            const QString& path)
{
    QFile f(path);
    if (!f.open(QIODevice::WriteOnly)) return false;

    QJsonObject root;

    // Next ID
    root["next_id"] = (double)nextProductId;

    // Buffers
    QJsonObject buffers;
    buffers["entry"] = bufferToJson(line->entryBuffer());

    int i = 0;
    for (auto* buf : line->internalBuffers())
        buffers[QString("buf_%1").arg(i++)] = bufferToJson(buf);

    root["buffers"] = buffers;

    // Stations + stats
    QJsonObject stations;
    for (auto* st : line->stations())
    {
        QJsonObject obj;
        obj["running"] = st->isRunning();
        obj["paused"]  = st->isPaused();
        obj["stats"]   = stationStatsToJson(st);
        stations[st->name()] = obj;
    }

    root["stations"] = stations;

    QJsonDocument doc(root);
    f.write(doc.toJson());
    return true;
}

//STATEs

bool Persistence::loadState(ProductionLine* line,
                            long& nextProductId,
                            const QString& path)
{
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly)) return false;

    QJsonDocument doc = QJsonDocument::fromJson(f.readAll());
    if (!doc.isObject()) return false;

    QJsonObject root = doc.object();

    // Next ID
    nextProductId = root["next_id"].toInt();

    // Buffers
    QJsonObject buffers = root["buffers"].toObject();
    jsonToBuffer(buffers["entry"].toArray(), line->entryBuffer());

    int i = 0;
    for (auto* buf : line->internalBuffers())
        jsonToBuffer(buffers[QString("buf_%1").arg(i++)].toArray(), buf);

    // Stations + stats
    QJsonObject stations = root["stations"].toObject();
    for (auto* st : line->stations())
    {
        QJsonObject obj = stations[st->name()].toObject();
        jsonToStationStats(obj["stats"].toObject(), st);
    }

    return true;
}

//LOG

void Persistence::appendLog(const QString& line,
                            const QString& path)
{
    QFile f(path);
    f.open(QIODevice::Append);

    QString out = QString("[%1] %2\n")
                      .arg(QDateTime::currentDateTime().toString("hh:mm:ss"))
                      .arg(line);

    f.write(out.toUtf8());
}
