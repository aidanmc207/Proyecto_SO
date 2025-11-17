#include "ThreadManager.h"
#include <QFile>
#include <QDateTime>

ThreadManager::ThreadManager(ProductionLine* line, QObject* parent)
    : QObject(parent)
    , m_line(line)
{
    // cada cierto tiempo limpiamos
    connect(&m_cleanTimer, &QTimer::timeout,
            this, &ThreadManager::doClean);

    // cada cierto tiempo publicamos estadísticas
    connect(&m_statsTimer, &QTimer::timeout,
            this, &ThreadManager::doStats);
}

void ThreadManager::startAll()
{
    emit log(">> Iniciando hilos de mantenimiento del sistema <<");
    emit log("GeneralLogs: Sistema de logs activado");

    // Timer para limpieza general cada 15 segundos
    m_cleanTimer.start(15000);
    emit log("GeneralCleanThreads: Programado cada 15 segundos");

    // Timer para estadísticas cada segundo
    m_statsTimer.start(1000);
    emit log("GeneralStats: Programado cada 1 segundo");

    emit log(">> Todos los hilos de mantenimiento están activos <<");
}

void ThreadManager::stopAll()
{
    emit log(">> Deteniendo hilos de mantenimiento <<");

    m_cleanTimer.stop();
    emit log("GeneralCleanThreads: Detenido");

    m_statsTimer.stop();
    emit log("GeneralStats: Detenido");

    emit log("GeneralLogs: Sigue activo para mensajes finales");
    emit log(">> Hilos de mantenimiento detenidos <<");
}

void ThreadManager::pushLog(const QString& text)
{
    // GeneralLogs: Guarda todos los mensajes del sistema en un archivo
    // con fecha, hora y categoría para poder revisar qué pasó después
    QFile f("runtime.log");
    if (f.open(QIODevice::Append))
    {
        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        QString category = "INFO";

        // Decidir qué tipo de mensaje es
        if (text.contains("error", Qt::CaseInsensitive) || text.contains("fail", Qt::CaseInsensitive))
            category = "ERROR";
        else if (text.contains("warning", Qt::CaseInsensitive) || text.contains("alert", Qt::CaseInsensitive))
            category = "WARN";
        else if (text.contains("start") || text.contains("stop") || text.contains("pause"))
            category = "ACTION";
        else if (text.contains("Generated") || text.contains("processed"))
            category = "PRODUCTION";
        else if (text.contains("Thread") || text.contains("General"))
            category = "MAINTENANCE";

        QString line = QString("[%1] [%2] %3\n")
                           .arg(timestamp, category, text);
        f.write(line.toUtf8());
    }

    // Enviar el mensaje también a la interfaz gráfica
    emit log(text);
}

void ThreadManager::doClean()
{
    if (!m_line) return;

    emit log("--- GeneralCleanThreads: Iniciando limpieza ---");
    emit log("GeneralCleanThreads: Limpiando buffers y reseteando contadores...");

    // Limpiar todos los buffers entre estaciones
    int buffersLimpiados = 0;
    for (auto* buf : m_line->internalBuffers()) {
        if (buf) {
            int size = buf->size();
            buf->clear();
            buffersLimpiados++;
            emit log(QString("GeneralCleanThreads: Buffer limpiado (tenía %1 productos)").arg(size));
        }
    }

    // Limpiar buffer de entrada también
    if (m_line->entryBuffer()) {
        int size = m_line->entryBuffer()->size();
        m_line->entryBuffer()->clear();
        emit log(QString("GeneralCleanThreads: Buffer de entrada limpiado (tenía %1 productos)").arg(size));
    }

    // Resetear los contadores de todas las estaciones
    int estacionesReseteadas = 0;
    for (auto* st : m_line->stations()) {
        if (st) {
            long procesados = st->processedCount();
            st->resetCount();
            estacionesReseteadas++;
            emit log(QString("GeneralCleanThreads: Estación '%1' reseteada (había procesado %2)")
                    .arg(st->name()).arg(procesados));
        }
    }

    emit log(QString("GeneralCleanThreads: Limpieza completa. %1 buffers limpiados, %2 estaciones reseteadas.")
            .arg(buffersLimpiados).arg(estacionesReseteadas));
    emit log("--- GeneralCleanThreads: Limpieza finalizada ---");
}

void ThreadManager::doStats()
{
    if (!m_line) return;

    emit log("--- GeneralStats: Recopilando estadísticas del sistema ---");

    // Variables para acumular totales
    long totalProcesados = 0;
    long totalRetrabajo = 0;
    int totalEnCola = 0;

    // Revisar cada estación y sacar sus números
    for (auto* st : m_line->stations())
    {
        if (!st) continue;

        long procesados = st->processedCount();
        long retrabajo = st->reworkCount();
        int tamanioCola = st->inputBuffer() ? st->inputBuffer()->size() : 0;

        // Sumar a los totales
        totalProcesados += procesados;
        totalRetrabajo += retrabajo;
        totalEnCola += tamanioCola;

        // Enviar señal para actualizar la interfaz
        emit statsUpdated(st->name(), procesados, tamanioCola, retrabajo);

        // Mostrar estadísticas de esta estación
        emit log(QString("GeneralStats: %1 → Procesados: %2, En Cola: %3, Retrabajo: %4")
                .arg(st->name(), -20)
                .arg(procesados, 5)
                .arg(tamanioCola, 3)
                .arg(retrabajo, 4));
    }

    // Mostrar los totales generales
    emit log(QString("GeneralStats: TOTALES → Procesados: %1, En Cola: %2, Retrabajo: %3")
            .arg(totalProcesados).arg(totalEnCola).arg(totalRetrabajo));
    emit log("--- GeneralStats: Estadísticas recopiladas ---");
}
