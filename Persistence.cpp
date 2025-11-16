#include "Persistence.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

Persistence::Persistence(QObject* parent)
    : QObject(parent)
{
}

bool Persistence::saveProcessHistory(const QVector<Product>& history,
                                     const QString& filePath)
{
    QJsonArray arr;

    for (const Product& p : history)
    {
        QJsonObject obj;
        obj["id"] = QString::number(p.id);
        obj["type"] = p.type;
        obj["state"] = static_cast<int>(p.state);   // enum → int

        arr.append(obj);
    }

    QJsonObject root;
    root["products"] = arr;

    QJsonDocument doc(root);

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly))
    {
        emit log(QStringLiteral("Persistence: Cannot write file %1").arg(filePath));
        return false;
    }

    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();

    emit log(QStringLiteral("Persistence: saved %1 products").arg(history.size()));
    return true;
}

QVector<Product> Persistence::loadProcessHistory(const QString& filePath)
{
    QVector<Product> result;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        emit log(QStringLiteral("Persistence: Cannot read file %1").arg(filePath));
        return result;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) return result;

    QJsonObject root = doc.object();
    QJsonArray arr = root["products"].toArray();

    for (const QJsonValue& v : arr)
    {
        QJsonObject obj = v.toObject();
        Product p;

        p.id = obj["id"].toString().toLongLong();
        p.type = obj["type"].toString();
        p.state = static_cast<ProductState>(obj["state"].toInt());

        result.append(p);
    }

    emit log(QStringLiteral("Persistence: loaded %1 products").arg(result.size()));
    return result;
}
