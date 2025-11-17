#pragma once

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include "Buffer.h"
#include "product.h"

class WorkStation : public QObject
{
    Q_OBJECT
public:
    explicit WorkStation(const QString& name);
    virtual ~WorkStation();

    void setInputBuffer(Buffer<Product>* buf);
    void setOutputBuffer(Buffer<Product>* buf);
    Buffer<Product>* inputBuffer()  const { return m_input; }
    Buffer<Product>* outputBuffer() const { return m_output; }


    QString name() const { return m_name; }
    long processedCount() const { return m_processed; }
    void incrementCount() { m_processed++; }

    bool isRunning() const { return m_running; }
    bool isPaused()  const { return m_paused;  }

    //Hilos mantenimiento
    void resetCount() { m_processed = 0; }
    int inputBufferSize() const { return m_input ? m_input->size() : 0; }
    Product takeLastProcessed() const { return lastProcessed; }
    bool hasProcessed() const { return hasLastProcessed; }

    void injectProduct(const Product& p) {
        if (m_input) m_input->push(p);
    }
    long reworkCount() const { return m_reworkCount; }
    void incrementRework() { m_reworkCount++; }

public slots:
    void start();
    void pause();
    void stop();

signals:
    void statsUpdated(const QString& name, long processed, int queueSize,long reworks);
    void stationUpdated(const QString& name, const QString& state, int queueSize);
    void log(const QString& line);
    // Esta señal se usa para generar el siguiente producto justo a tiempo
    void consumed(const QString& stationName);

protected:
    virtual void process(Product& p) = 0;
    Product lastProcessed;
    bool hasLastProcessed = false;

private slots:
    void runLoop();

private:
    long m_processed = 0;
    long m_reworkCount = 0;
    QString m_name;
    Buffer<Product>* m_input  = nullptr;
    Buffer<Product>* m_output = nullptr;

    QThread m_thread;
    bool m_running = false;
    bool m_paused  = false;

    QMutex m_pauseMutex;
    QWaitCondition m_pauseCond;

    QString stateString() const;
};
