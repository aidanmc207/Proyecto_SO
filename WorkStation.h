#pragma once

#include <QObject>
#include <QString>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <atomic>

#include "Buffer.h"
#include "Product.h"

class WorkStation : public QObject
{
    Q_OBJECT
public:
    explicit WorkStation(const QString& name, QObject* parent = nullptr);
    virtual ~WorkStation();

    void setInputBuffer(Buffer<Product>* buf);
    void setOutputBuffer(Buffer<Product>* buf);

    QString name() const { return m_name; }

public slots:
    void start();   // inicia el hilo y el loop
    void pause();   // pausa el procesamiento
    void stop();    // detiene el hilo

signals:
    // name, estado ("Running", "Paused", "Stopped"), tamaño de cola de entrada
    void stationUpdated(const QString& name, const QString& state, int queueSize);
    void log(const QString& line);

protected:
    virtual void process(Product& p) = 0;   // implementado por Assembler/Tester/Packer

private slots:
    void runLoop(); // loop interno que se conecta a QThread::started()

private:
    QString m_name;
    Buffer<Product>* m_input { nullptr };
    Buffer<Product>* m_output { nullptr };

    QThread m_thread;
    std::atomic<bool> m_running { false };
    std::atomic<bool> m_paused  { false };

    QMutex m_pauseMutex;
    QWaitCondition m_pauseCond;

    QString stateString() const;
};
