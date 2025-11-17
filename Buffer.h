#pragma once

#include <QMutex>
#include <QWaitCondition>
#include <queue>

// Buffer: Cola de productos protegida para que varios hilos puedan usarla
// sin problemas. Usa QMutex para que no haya condiciones de carrera
// y QWaitCondition para esperar cuando está lleno o vacío
template <typename T>
class Buffer {
public:
    explicit Buffer(int capacity = 32)
        : m_capacity(capacity)
    {}

    void push(const T& item) {
        QMutexLocker locker(&m_mutex);
        while ((int)m_queue.size() >= m_capacity && !m_shutdown)
            m_notFull.wait(&m_mutex);

        if (m_shutdown) return;

        m_queue.push(item);
        m_notEmpty.wakeOne();
    }

    T pop() {
        QMutexLocker locker(&m_mutex);
        while (m_queue.empty() && !m_shutdown)
            m_notEmpty.wait(&m_mutex);

        if (m_shutdown && m_queue.empty())
            return T{};   // dummy si estamos apagando

        T v = m_queue.front();
        m_queue.pop();
        m_notFull.wakeOne();
        return v;
    }

    int size() const {
        QMutexLocker locker(&m_mutex);
        return (int)m_queue.size();
    }
    void clear() {
        QMutexLocker locker(&m_mutex);

        std::queue<T> empty;
        std::swap(m_queue, empty);

        // si estaba apagado anteriormente, lo volvemos a habilitar
        m_shutdown = false;

        m_notFull.wakeAll();
    }


    void shutdown() {
        QMutexLocker locker(&m_mutex);
        m_shutdown = true;
        m_notEmpty.wakeAll();
        m_notFull.wakeAll();
    }
    QVector<T> toVector() const {
        QMutexLocker lock(&m_mutex);
        QVector<T> v;

        std::queue<T> copy = m_queue;

        while (!copy.empty()) {
            v.append(copy.front());
            copy.pop();
        }

        return v;
    }



private:

    int m_capacity;
    mutable QMutex m_mutex;
    QWaitCondition m_notEmpty;
    QWaitCondition m_notFull;
    std::queue<T> m_queue;
    bool m_shutdown = false;
};
