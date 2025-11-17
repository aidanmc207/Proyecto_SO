#pragma once
#include <QObject>
#include <QRandomGenerator>
#include "ProductionLine.h"
#include "Assembler.h"
#include "Tester.h"
#include "Packer.h"
#include "Shipping.h"
#include "Buffer.h"
#include "product.h"
#include "Persistence.h"
#include "ThreadManager.h"
#include "QualityControl.h"
#include "PipeManager.h"
#include "LogWindow.h"


class ProductionController : public QObject
{
    Q_OBJECT
public:
    explicit ProductionController(QObject* parent = nullptr);
    void saveState();

public slots:
    void start();
    void pause();
    void stop();

    // Control individual de estaciones
    void startStation(const QString& stationName);
    void pauseStation(const QString& stationName);
    void stopStation(const QString& stationName);
     void setLogWindow(LogWindow* win);

signals:
    void logLine(const QString& line);
    void stationUpdated(const QString& name, const QString& state, int queueSize);
    void statsUpdated(const QString& station, long processed, int queueSize, long rework);

private slots:
    void onStationConsumed(const QString& stationName);

private:
    void generateProduct();
    Buffer<Product>* m_entry1 = nullptr;
    Buffer<Product>* m_entry2 = nullptr;
    bool m_toggle = false;   // alternador
    LogWindow* logWin = nullptr;

    ProductionLine* m_line = nullptr;
    bool m_running = false;
    bool m_paused  = false;

    long nextProductId = 1;
    Persistence* persistence = nullptr;
    ThreadManager*   maintenance     = nullptr;
    Buffer<Product>* m_bufAsmToTest = nullptr;    
    PipeManager*     m_pipeManager   = nullptr;
};
