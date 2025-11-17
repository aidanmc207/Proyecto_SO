#pragma once

#include <QObject>
#include <QRandomGenerator>
#include <thread>
#include <atomic>
#include <unistd.h>

#include "Buffer.h"
#include "product.h"

// PipeManager: Maneja la comunicación por pipes (IPC) para los productos
// que fallan en Quality Control y necesitan regresar a ensamblaje.
// Usa pipes de Unix reales (no simulados) y un hilo separado para leer
class PipeManager : public QObject
{
    Q_OBJECT
public:
    explicit PipeManager(Buffer<Product>* targetBuffer,
                         QObject* parent = nullptr);
    ~PipeManager();

    // Llamado desde QualityControl cuando un producto falla
    void sendToPipe(const Product& p);

signals:
    void log(const QString& line);

private:
    int m_fd[2]{-1, -1};             // 0 = read, 1 = write
    std::thread m_reader;
    std::atomic<bool> m_running{false};
    Buffer<Product>* m_targetBuffer = nullptr; // normalmente entryBuffer

    void readerLoop();   // corre en std::thread
};
