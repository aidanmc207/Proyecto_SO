#pragma once
#include <QObject>
#include <QThread>
#include <atomic>
#include "Buffer.h"
#include "Product.h"

class WorkStation : public QObject {
    Q_OBJECT
public:
    void launch();   // arranca QThread desde el hilo llamador (GUI)
public slots:
    void start();    // solo cambia flags (no llama m_thread.start)
    void pause();
    void stop();

signals:
    void updated(const QString& station, const QString& state, int progress);
    void log(const QString& line);

protected:
    virtual void process(Product& p)=0;
    void runLoop();

private:
    QString m_name; QThread m_thread; std::atomic_bool m_running{false}; std::atomic_bool m_paused{false};
    Buffer<Product>* m_in=nullptr; Buffer<Product>* m_out=nullptr;
};
