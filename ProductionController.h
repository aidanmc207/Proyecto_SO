#pragma once
#include <QObject>
#include <QRandomGenerator>
#include "ProductionLine.h"
#include "Assembler.h"
#include "Tester.h"
#include "Packer.h"
#include "Buffer.h"
#include "product.h"
#include "Persistence.h"
#include "ThreadManager.h"
#include "QualityControl.h"
#include "PipeManager.h"


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

signals:
    void logLine(const QString& line);
    void stationUpdated(const QString& name, const QString& state, int queueSize);
    void statsUpdated(const QString& station, long processed, int queueSize);

private slots:
    void onStationConsumed(const QString& stationName);

private:
    void generateProduct();

    ProductionLine* m_line = nullptr;
    bool m_running = false;
    bool m_paused  = false;

    long nextProductId = 1;
    Persistence* persistence = nullptr;
    ThreadManager*   maintenance     = nullptr;
    Buffer<Product>* m_bufAsmToTest = nullptr;    
    PipeManager*     m_pipeManager   = nullptr;
};
