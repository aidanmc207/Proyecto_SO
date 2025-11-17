#include "MainWindow.h"
#include "ProductionController.h"
#include "StatsMonitor.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QHBoxLayout>
#include <QVBoxLayout>

class MainWindow::Impl {
public:
    Ui::MainWindow ui;
    ProductionController* controller = nullptr;
};

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), d(new Impl)
{
    d->ui.setupUi(this);

    d->controller = new ProductionController(this);

    //conexiones UI
    connect(this, &MainWindow::startProduction,
            d->controller, &ProductionController::start);

    connect(this, &MainWindow::pauseProduction,
            d->controller, &ProductionController::pause);

    connect(this, &MainWindow::stopProduction,
            d->controller, &ProductionController::stop);

    connect(d->controller, &ProductionController::stationUpdated,
            this, &MainWindow::updateStation);

    connect(d->controller, &ProductionController::logLine,
            this, &MainWindow::appendLog);

    //stats/UI
    connect(d->controller, &ProductionController::statsUpdated,
            this, &MainWindow::updateStats);

    //botones globales
    connect(d->ui.btnStart, &QPushButton::clicked,
            this, [this]{ emit startProduction(); });

    connect(d->ui.btnPause, &QPushButton::clicked,
            this, [this]{ emit pauseProduction(); });

    connect(d->ui.btnStop, &QPushButton::clicked,
            this, [this]{ emit stopProduction(); });

    // Botones individuales para Assembler
    connect(d->ui.btnAsmStart, &QPushButton::clicked,
            this, [this]{ emit startStation("Assembler"); });
    connect(d->ui.btnAsmPause, &QPushButton::clicked,
            this, [this]{ emit pauseStation("Assembler"); });
    connect(d->ui.btnAsmStop, &QPushButton::clicked,
            this, [this]{ emit stopStation("Assembler"); });

    // Botones individuales para Tester
    connect(d->ui.btnTesStart, &QPushButton::clicked,
            this, [this]{ emit startStation("Tester"); });
    connect(d->ui.btnTesPause, &QPushButton::clicked,
            this, [this]{ emit pauseStation("Tester"); });
    connect(d->ui.btnTesStop, &QPushButton::clicked,
            this, [this]{ emit stopStation("Tester"); });

    // Botones individuales para Quality Control
    connect(d->ui.btnQCStart, &QPushButton::clicked,
            this, [this]{ emit startStation("QualityControl"); });
    connect(d->ui.btnQCPause, &QPushButton::clicked,
            this, [this]{ emit pauseStation("QualityControl"); });
    connect(d->ui.btnQCStop, &QPushButton::clicked,
            this, [this]{ emit stopStation("QualityControl"); });

    // Botones individuales para Packer
    connect(d->ui.btnPacStart, &QPushButton::clicked,
            this, [this]{ emit startStation("Packer"); });
    connect(d->ui.btnPacPause, &QPushButton::clicked,
            this, [this]{ emit pauseStation("Packer"); });
    connect(d->ui.btnPacStop, &QPushButton::clicked,
            this, [this]{ emit stopStation("Packer"); });

    // Botones individuales para Shipping
    connect(d->ui.btnShipStart, &QPushButton::clicked,
            this, [this]{ emit startStation("Shipping"); });
    connect(d->ui.btnShipPause, &QPushButton::clicked,
            this, [this]{ emit pauseStation("Shipping"); });
    connect(d->ui.btnShipStop, &QPushButton::clicked,
            this, [this]{ emit stopStation("Shipping"); });

    // Conectar las señales de controles individuales al controlador
    connect(this, &MainWindow::startStation,
            d->controller, &ProductionController::startStation);
    connect(this, &MainWindow::pauseStation,
            d->controller, &ProductionController::pauseStation);
    connect(this, &MainWindow::stopStation,
            d->controller, &ProductionController::stopStation);

    // Configurar gráficos
    setupCharts();

    // Conectar actualización de gráficos
    if (d->controller->statsMonitor()) {
        connect(d->controller->statsMonitor(), &StatsMonitor::dataUpdated,
                this, &MainWindow::updateCharts);
    }
}

MainWindow::~MainWindow()
{
    if (d->controller)
        d->controller->saveState();

    delete d;
}

void MainWindow::updateStation(const QString& station,
                               const QString& state,
                               int queueSize)
{
    if (station.startsWith("Assembler")) {
        d->ui.lblAsmState->setText(state);
        d->ui.barAsm1->setValue(queueSize);
    }
    else if (station == "Tester") {
        d->ui.lblTesState->setText(state);
        d->ui.barTes->setValue(queueSize);
    }
    else if (station == "QualityControl") {
        d->ui.lblQCState->setText(state);
        d->ui.barQC->setValue(queueSize);
    }
    else if (station == "Packer") {
        d->ui.lblPacState->setText(state);
        d->ui.barPac->setValue(queueSize);
    }
    else if (station == "Shipping") {
        d->ui.lblShipState->setText(state);
        d->ui.barShip->setValue(queueSize);
    }

    statusBar()->showMessage(QString("%1: %2").arg(station, state), 2000);
}

//STATS
void MainWindow::updateStats(const QString& station,
                             long processed,
                             int queueSize,
                             long rework)
{
    if (station == "Assembler-1") {
        d->ui.lblAsm1Processed->setText(QString("Assembled: %1").arg(processed));
        d->ui.barAsm1->setValue(queueSize);
    }
    else if (station == "Assembler-2") {
        d->ui.lblAsm2Processed->setText(QString("Assembled: %1").arg(processed));
        d->ui.barAsm2->setValue(queueSize);
    }
    else if (station == "Tester") {
        d->ui.lblTesProcessed->setText(QString("Tested: %1").arg(processed));
        d->ui.barTes->setValue(queueSize);
    }
    else if (station == "QualityControl") {
        d->ui.lblQCProcessed->setText(QString("Reviewed: %1").arg(processed));
        d->ui.lblQCRework->setText(QString("Reworking: %1").arg(rework));
        d->ui.barQC->setValue(queueSize);
    }
    else if (station == "Packer") {
        d->ui.lblPacProcessed->setText(QString("Packed: %1").arg(processed));
        d->ui.barPac->setValue(queueSize);
    }
    else if (station == "Shipping") {
        d->ui.lblShipProcessed->setText(QString("Shipped: %1").arg(processed));
        d->ui.barShip->setValue(queueSize);
    }

    updateGlobalRework();

    statusBar()->showMessage(
        QString("%1 → %2 items procesados")
            .arg(station)
            .arg(processed),
        2000
        );
}

//LOG
void MainWindow::appendLog(const QString& line)
{
    d->ui.txtLogs->appendPlainText(line);
}
void MainWindow::updateGlobalRework()
{
    long total = d->ui.lblQCRework->text().toLong();

    d->ui.lblTotalRework->setText(QString::number(total));
}

// Widget personalizado para graficar
class MainWindow::ChartWidget : public QWidget
{
public:
    explicit ChartWidget(QWidget* parent = nullptr) : QWidget(parent) {
        setMinimumHeight(200);
        setMaximumHeight(250);
        setStyleSheet("background-color: white; border: 1px solid gray;");
    }

    void setData(const QVector<double>& timestamps,
                 const QVector<double>& processed,
                 const QVector<double>& queue,
                 const QVector<double>& rework)
    {
        m_timestamps = timestamps;
        m_processed = processed;
        m_queue = queue;
        m_rework = rework;
        update();
    }

protected:
    void paintEvent(QPaintEvent*) override
    {
        if (m_timestamps.isEmpty()) return;

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // Márgenes
        const int margin = 50;
        const int chartWidth = width() - 2 * margin;
        const int chartHeight = height() - 2 * margin;

        // Dibujar ejes
        painter.setPen(Qt::black);
        painter.drawLine(margin, height() - margin, width() - margin, height() - margin); // Eje X
        painter.drawLine(margin, margin, margin, height() - margin); // Eje Y

        // Título
        painter.drawText(rect(), Qt::AlignTop | Qt::AlignHCenter, "Estadísticas en Tiempo Real");

        // Encontrar valores máximos
        double maxValue = 1.0;
        for (double val : m_processed) maxValue = qMax(maxValue, val);
        for (double val : m_queue) maxValue = qMax(maxValue, val);
        for (double val : m_rework) maxValue = qMax(maxValue, val);

        double minTime = m_timestamps.first();
        double maxTime = m_timestamps.last();
        double timeRange = maxTime - minTime;
        if (timeRange < 1) timeRange = 1;

        // Dibujar líneas
        auto drawSeries = [&](const QVector<double>& data, const QColor& color, const QString& label) {
            if (data.size() < 2) return;

            painter.setPen(QPen(color, 2));
            for (int i = 0; i < data.size() - 1; ++i) {
                double x1 = margin + (m_timestamps[i] - minTime) / timeRange * chartWidth;
                double y1 = height() - margin - (data[i] / maxValue) * chartHeight;
                double x2 = margin + (m_timestamps[i+1] - minTime) / timeRange * chartWidth;
                double y2 = height() - margin - (data[i+1] / maxValue) * chartHeight;
                painter.drawLine(QPointF(x1, y1), QPointF(x2, y2));
            }
        };

        // Dibujar series
        drawSeries(m_processed, Qt::blue, "Procesados");
        drawSeries(m_queue, Qt::red, "En Cola");
        drawSeries(m_rework, Qt::green, "Retrabajo");

        // Leyenda
        int legendY = margin + 20;
        painter.setPen(Qt::blue);
        painter.drawText(width() - 150, legendY, "Procesados");
        painter.setPen(Qt::red);
        painter.drawText(width() - 150, legendY + 20, "En Cola");
        painter.setPen(Qt::green);
        painter.drawText(width() - 150, legendY + 40, "Retrabajo");

        // Etiquetas de ejes
        painter.setPen(Qt::black);
        painter.drawText(margin, height() - 10, QString::number(minTime, 'f', 0));
        painter.drawText(width() - margin - 30, height() - 10, QString::number(maxTime, 'f', 0));
        painter.drawText(10, margin, QString::number((int)maxValue));
        painter.drawText(10, height() - margin, "0");
    }

private:
    QVector<double> m_timestamps;
    QVector<double> m_processed;
    QVector<double> m_queue;
    QVector<double> m_rework;
};

void MainWindow::setupCharts()
{
    // Crear widget de gráfico personalizado
    m_chartWidget = new ChartWidget(this);
    m_chartWidget->setMinimumWidth(400);
    m_chartWidget->setMaximumWidth(600);

    // Crear un layout horizontal para logs y gráfico
    QWidget* bottomWidget = new QWidget(this);
    QHBoxLayout* bottomLayout = new QHBoxLayout(bottomWidget);

    // Limitar altura del área de logs y gráfico
    bottomWidget->setMaximumHeight(250);

    // Mover el widget de logs del layout principal al layout horizontal
    QWidget* logsWidget = d->ui.txtLogs;

    // Crear un widget contenedor para los logs y el label de rework
    QWidget* logsContainer = new QWidget();
    QVBoxLayout* logsLayout = new QVBoxLayout(logsContainer);
    logsLayout->setContentsMargins(0, 0, 0, 0);

    // Remover el label de total rework del layout actual y agregarlo al contenedor
    d->ui.lblTotalRework->setParent(logsContainer);
    logsLayout->addWidget(d->ui.lblTotalRework);

    // Remover txtLogs del layout y agregarlo al contenedor
    logsWidget->setParent(logsContainer);
    logsWidget->setMaximumHeight(220); // Limitar altura de logs
    logsLayout->addWidget(logsWidget);

    // Agregar contenedor de logs y gráfico al layout horizontal
    bottomLayout->addWidget(logsContainer, 2); // 2/3 del espacio para logs
    bottomLayout->addWidget(m_chartWidget, 1); // 1/3 del espacio para gráfico

    // Agregar el widget horizontal al layout principal
    d->ui.rootLayout->addWidget(bottomWidget);
}

void MainWindow::updateCharts()
{
    if (!d->controller || !d->controller->statsMonitor() || !m_chartWidget) return;

    StatsMonitor* monitor = d->controller->statsMonitor();

    // Obtener datos
    QVector<double> timestamps = monitor->getTimestamps();
    QVector<double> processed = monitor->getTotalProcessed();
    QVector<double> queue = monitor->getTotalInQueue();
    QVector<double> rework = monitor->getTotalRework();

    if (timestamps.isEmpty()) return;

    // Actualizar el widget
    m_chartWidget->setData(timestamps, processed, queue, rework);

    // Exportar datos a CSV periódicamente
    exportChartData();
}

void MainWindow::exportChartData()
{
    if (!d->controller || !d->controller->statsMonitor()) return;

    StatsMonitor* monitor = d->controller->statsMonitor();
    QVector<double> timestamps = monitor->getTimestamps();
    QVector<double> processed = monitor->getTotalProcessed();
    QVector<double> queue = monitor->getTotalInQueue();
    QVector<double> rework = monitor->getTotalRework();

    if (timestamps.isEmpty()) return;

    QFile file("stats_chart.csv");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Time,Processed,InQueue,Rework\n";

        for (int i = 0; i < timestamps.size(); ++i) {
            out << timestamps[i] << ","
                << processed[i] << ","
                << queue[i] << ","
                << rework[i] << "\n";
        }
    }
}

