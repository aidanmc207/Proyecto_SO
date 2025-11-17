#include "PipeManager.h"
#include <QDebug>

PipeManager::PipeManager(Buffer<Product>* targetBuffer,
                         QObject* parent)
    : QObject(parent)
    , m_targetBuffer(targetBuffer)
{
    if (::pipe(m_fd) < 0) {
        perror("pipe");
        m_fd[0] = m_fd[1] = -1;
        return;
    }

    m_running = true;

    // Lanzamos hilo lector (NO es QThread, así no tocamos Qt)
    m_reader = std::thread([this]{
        readerLoop();
    });

    emit log("PipeManager: started reader thread");
}

PipeManager::~PipeManager()
{
    m_running = false;

    if (m_fd[0] != -1) ::close(m_fd[0]);
    if (m_fd[1] != -1) ::close(m_fd[1]);

    if (m_reader.joinable())
        m_reader.join();

    emit log("PipeManager: stopped");
}

void PipeManager::sendToPipe(const Product& p)
{
    if (m_fd[1] == -1) return;

    ProductPipeData d = toPipeData(p);

    ssize_t n = ::write(m_fd[1], &d, sizeof(d));
    if (n != sizeof(d)) {
        emit log("PipeManager: write() incomplete or failed");
        return;
    }

    emit log(QString("PipeManager: sent via pipe %1").arg(p.show()));
}

void PipeManager::readerLoop()
{
    if (m_fd[0] == -1) return;

    while (m_running)
    {
        ProductPipeData d{};
        ssize_t n = ::read(m_fd[0], &d, sizeof(d));

        if (n == sizeof(d))
        {
            Product p = fromPipeData(d);
            p.state = ProductState::Rework;

            if (m_targetBuffer)
                m_targetBuffer->push(p);    // re-trabajo a la entrada

            emit log(QString("PipeManager: received from pipe %1 → requeued")
                         .arg(p.show()));
        }
        else if (n <= 0)
        {
            // pipe cerrado o error
            break;
        }
    }
}
