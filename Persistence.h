#pragma once
#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include "product.h"
#include "ProductionLine.h"

class Persistence : public QObject
{
    Q_OBJECT
public:
    explicit Persistence(QObject* parent = nullptr);

    bool saveState(const ProductionLine* line,
                   long nextProductId,
                   const QString& path = "save_state.json");

    bool loadState(ProductionLine* line,
                   long& nextProductId,
                   const QString& path = "save_state.json");

    void appendLog(const QString& line,
                   const QString& path = "log_history.json");

private:
    QJsonObject productToJson(const Product& p) const;
    Product jsonToProduct(const QJsonObject& obj) const;

    QJsonArray bufferToJson(const Buffer<Product>* buf) const;
    void jsonToBuffer(const QJsonArray& arr, Buffer<Product>* buf) const;

    QJsonObject stationStatsToJson(const WorkStation* st) const;
    void jsonToStationStats(const QJsonObject& obj, WorkStation* st) const;
};
