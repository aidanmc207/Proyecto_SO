#pragma once
#include <QObject>
#include <QString>

class CleanUpService : public QObject {
    Q_OBJECT
public:
    explicit CleanUpService(QObject* parent=nullptr);
public slots:
    void resetAll();
signals:
    void info(const QString& msg);
};
