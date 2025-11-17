#pragma once
#include <QObject>
#include <QTimer>
#include "ProductionLine.h"

class ThreadManager : public QObject
{
    Q_OBJECT
public:
    explicit ThreadManager(ProductionLine* line, QObject* parent = nullptr);

    void startAll();
    void stopAll();

public slots:
    void pushLog(const QString& text);

signals:
    void log(const QString& text);
    void statsUpdated(const QString& station, long processed, int bufferSize,long reworkCount);

private slots:
    void doClean();   // "GeneralCleanThreads"
    void doStats();   // "GeneralStats"

private:
    ProductionLine* m_line = nullptr;

    QTimer m_cleanTimer;
    QTimer m_statsTimer;
};
