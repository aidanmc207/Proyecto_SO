
#pragma once
#include <queue>
#include <QMutex>
#include <QWaitCondition>

template <typename T>
class Buffer {
public:
    explicit Buffer(int capacity=32) : m_capacity(capacity) {}

    void push(const T& item){
        QMutexLocker locker(&m_mutex);
        while((int)m_queue.size()>=m_capacity) m_notFull.wait(&m_mutex);
        m_queue.push(item);
        m_notEmpty.wakeOne();
    }

    T pop(){
        QMutexLocker locker(&m_mutex);
        while(m_queue.empty()) m_notEmpty.wait(&m_mutex);
        T v = m_queue.front(); m_queue.pop();
        m_notFull.wakeOne();
        return v;
    }

    int size() const { QMutexLocker l(&m_mutex); return (int)m_queue.size(); }

private:
    mutable QMutex m_mutex;
    QWaitCondition m_notEmpty, m_notFull;
    std::queue<T> m_queue;
    int m_capacity;
};
