#pragma once
#include <QObject>
#include <QThread>
#include <QList>
#include <QMutex>

class ThreadManager : public QObject
{
    Q_OBJECT
public:
    explicit ThreadManager(QObject* parent = nullptr);

    void registerThread(QThread* t);
    void stopAll();

signals:
    void log(const QString& line);

private:
    QList<QThread*> m_threads;
    QMutex m_mutex;
};
