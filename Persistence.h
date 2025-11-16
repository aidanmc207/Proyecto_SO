#pragma once
#include <QObject>
#include <QString>
#include <QVector>
#include "Product.h"

class Persistence : public QObject
{
    Q_OBJECT
public:
    explicit Persistence(QObject* parent = nullptr);

    // Guarda todos los productos procesados en JSON
    bool saveProcessHistory(const QVector<Product>& history,
                            const QString& filePath);

    // Carga el JSON y devuelve todos los productos almacenados
    QVector<Product> loadProcessHistory(const QString& filePath);

signals:
    void log(const QString& msg);
};
