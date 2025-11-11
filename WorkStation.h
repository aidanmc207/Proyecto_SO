#pragma once
#include <QObject>
#include <QThread>
#include <QString>
#include <atomic>
#include "Buffer.h"
#include "Product.h"

class WorkStation : public QObject {
    Q_OBJECT
public:
    explicit WorkStation(const QString& name, QObject* parent=nullptr);
    virtual ~WorkStation();

    void setBuffers(Buffer<Product>* in, Buffer<Product>* out){ m_in=in; m_out=out; }
    void launch();

public slots:
    void start();
    void pause();
    void stop();

signals:
    void updated(const QString& station, const QString& state, int progress);
    void log(const QString& line);

protected:
    virtual void process(Product& p)=0;
    void runLoop();

private:
    QString m_name;
    QThread m_thread;
    std::atomic_bool m_running{false};
    std::atomic_bool m_paused{false};
    Buffer<Product>* m_in=nullptr;
    Buffer<Product>* m_out=nullptr;
};
