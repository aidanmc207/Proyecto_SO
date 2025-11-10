#pragma once
#include <QObject>
#include <QString>

class Logger : public QObject {
    Q_OBJECT
public:
    explicit Logger(QObject* parent=nullptr);   // DECLARACIÓN, no implementación aquí
signals:
    void line(const QString& s);
public slots:
    void emitLine(const QString& s);
};
