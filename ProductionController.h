#pragma once
#include <QObject>

class ProductionLine; class Logger; class StatsMonitor; class CleanUpService;

class ProductionController : public QObject {
    Q_OBJECT
public:
    explicit ProductionController(QObject* parent=nullptr);
    bool infiniteMode = false;
    int targetAmount = 0;
    int producedCount = 0;
    QTimer* generatorTimer = nullptr;

public slots:
    void start();
    void pause();
    void stop();

signals:
    void stationUpdated(const QString&, const QString&, int);
    void logLine(const QString&);
    void threadList(const QStringList&);

private:
    ProductionLine* m_line; Logger* m_logger; StatsMonitor* m_stats; CleanUpService* m_cleaner;
    void init();
};
