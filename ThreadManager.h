#pragma once
#include <QObject>
#include <QTimer>
#include "ProductionLine.h"

// ThreadManager: Maneja los 3 hilos de mantenimiento que necesita el sistema
//
// 1. GeneralCleanThreads (cada 15 segundos):
//    Limpia buffers y resetea contadores para evitar acumulación
//
// 2. GeneralLogs (siempre activo):
//    Guarda todos los eventos en runtime.log con fecha y categoría
//
// 3. GeneralStats (cada 1 segundo):
//    Recopila estadísticas de todas las estaciones y calcula totales
//
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
