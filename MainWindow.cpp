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
    //CB
    d->ui.cmbSpeed->addItem("Fast");
    d->ui.cmbSpeed->addItem("Normal");
    d->ui.cmbSpeed->addItem("Slow");
    d->ui.cmbSpeed->setCurrentIndex(1);//default


    // Aplicar estilos modernos
    setupModernStyles();

    // Reorganizar layout en dos columnas
    reorganizeLayout();

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
    //CB
    connect(d->ui.cmbSpeed,
            static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this,
            &MainWindow::changeSpeedMode);

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
        setStyleSheet("background-color: #ffffff; border: 2px solid #e0e0e0; border-radius: 8px;");
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
        painter.setRenderHint(QPainter::TextAntialiasing);

        // Fondo con gradiente
        QLinearGradient bgGradient(0, 0, 0, height());
        bgGradient.setColorAt(0, QColor(255, 255, 255));
        bgGradient.setColorAt(1, QColor(250, 250, 255));
        painter.fillRect(rect(), bgGradient);

        // Márgenes
        const int marginLeft = 55;
        const int marginRight = 170;
        const int marginTop = 50;
        const int marginBottom = 40;
        const int chartWidth = width() - marginLeft - marginRight;
        const int chartHeight = height() - marginTop - marginBottom;

        // Título con mejor tipografía
        QFont titleFont("Arial", 13, QFont::Bold);
        painter.setFont(titleFont);
        painter.setPen(QColor(51, 51, 51));
        painter.drawText(rect().adjusted(0, 10, 0, 0), Qt::AlignTop | Qt::AlignHCenter,
                        "Estadísticas del Sistema en Tiempo Real");

        // Dibujar grid de fondo
        painter.setPen(QPen(QColor(230, 230, 230), 1, Qt::DotLine));
        for (int i = 1; i < 5; ++i) {
            int y = marginTop + (chartHeight * i / 5);
            painter.drawLine(marginLeft, y, marginLeft + chartWidth, y);
        }

        // Ejes principales
        painter.setPen(QPen(QColor(100, 100, 100), 2));
        painter.drawLine(marginLeft, height() - marginBottom,
                        width() - marginRight, height() - marginBottom); // Eje X
        painter.drawLine(marginLeft, marginTop, marginLeft, height() - marginBottom); // Eje Y

        // Encontrar valores máximos
        double maxValue = 1.0;
        for (double val : m_processed) maxValue = qMax(maxValue, val);
        for (double val : m_queue) maxValue = qMax(maxValue, val);
        for (double val : m_rework) maxValue = qMax(maxValue, val);

        double minTime = m_timestamps.first();
        double maxTime = m_timestamps.last();
        double timeRange = maxTime - minTime;
        if (timeRange < 1) timeRange = 1;

        // Dibujar líneas con sombra
        auto drawSeries = [&](const QVector<double>& data, const QColor& color, int width) {
            if (data.size() < 2) return;

            // Sombra
            painter.setPen(QPen(QColor(0, 0, 0, 30), width + 1));
            for (int i = 0; i < data.size() - 1; ++i) {
                double x1 = marginLeft + (m_timestamps[i] - minTime) / timeRange * chartWidth;
                double y1 = height() - marginBottom - (data[i] / maxValue) * chartHeight + 2;
                double x2 = marginLeft + (m_timestamps[i+1] - minTime) / timeRange * chartWidth;
                double y2 = height() - marginBottom - (data[i+1] / maxValue) * chartHeight + 2;
                painter.drawLine(QPointF(x1, y1), QPointF(x2, y2));
            }

            // Línea principal
            painter.setPen(QPen(color, width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            for (int i = 0; i < data.size() - 1; ++i) {
                double x1 = marginLeft + (m_timestamps[i] - minTime) / timeRange * chartWidth;
                double y1 = height() - marginBottom - (data[i] / maxValue) * chartHeight;
                double x2 = marginLeft + (m_timestamps[i+1] - minTime) / timeRange * chartWidth;
                double y2 = height() - marginBottom - (data[i+1] / maxValue) * chartHeight;
                painter.drawLine(QPointF(x1, y1), QPointF(x2, y2));
            }

            // Puntos en los datos
            painter.setBrush(color);
            for (int i = 0; i < data.size(); ++i) {
                double x = marginLeft + (m_timestamps[i] - minTime) / timeRange * chartWidth;
                double y = height() - marginBottom - (data[i] / maxValue) * chartHeight;
                painter.drawEllipse(QPointF(x, y), 3, 3);
            }
        };

        // Dibujar series con colores modernos
        drawSeries(m_processed, QColor(33, 150, 243), 3);  // Azul Material
        drawSeries(m_queue, QColor(244, 67, 54), 3);       // Rojo Material
        drawSeries(m_rework, QColor(255, 152, 0), 3);      // Naranja Material

        // Leyenda con fondo
        int legendX = width() - marginRight + 10;
        int legendY = marginTop + 10;
        int legendWidth = 150;
        int legendHeight = 90;

        // Fondo de leyenda
        painter.setBrush(QColor(255, 255, 255, 240));
        painter.setPen(QPen(QColor(200, 200, 200), 1));
        painter.drawRoundedRect(legendX, legendY, legendWidth, legendHeight, 5, 5);

        // Items de leyenda
        QFont legendFont("Arial", 10);
        painter.setFont(legendFont);

        auto drawLegendItem = [&](int y, const QColor& color, const QString& text) {
            painter.setBrush(color);
            painter.setPen(Qt::NoPen);
            painter.drawEllipse(legendX + 10, y + 3, 10, 10);
            painter.setPen(QColor(51, 51, 51));
            painter.drawText(legendX + 25, y + 12, text);
        };

        drawLegendItem(legendY + 15, QColor(33, 150, 243), "Procesados");
        drawLegendItem(legendY + 40, QColor(244, 67, 54), "En Cola");
        drawLegendItem(legendY + 65, QColor(255, 152, 0), "Retrabajo");

        // Etiquetas de ejes
        QFont axisFont("Arial", 9);
        painter.setFont(axisFont);
        painter.setPen(QColor(100, 100, 100));

        // Eje X
        painter.drawText(marginLeft - 10, height() - marginBottom + 20, QString::number(minTime, 'f', 0) + "s");
        painter.drawText(width() - marginRight - 20, height() - marginBottom + 20, QString::number(maxTime, 'f', 0) + "s");
        painter.drawText(marginLeft + chartWidth/2 - 20, height() - 10, "Tiempo (s)");

        // Eje Y
        painter.drawText(5, marginTop, QString::number((int)maxValue));
        painter.drawText(20, height() - marginBottom + 5, "0");
        painter.save();
        painter.translate(15, marginTop + chartHeight/2);
        painter.rotate(-90);
        painter.drawText(-30, 0, "Cantidad");
        painter.restore();
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

void MainWindow::setupModernStyles()
{
    // Estilo general de la aplicación css interno
    QString mainStyle = R"(
        QMainWindow {
            background-color: #f5f5f5;
        }

        QPushButton {
            background-color: #4CAF50;
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 4px;
            font-weight: bold;
            font-size: 11px;
            min-width: 70px;
        }

        QPushButton:hover {
            background-color: #45a049;
        }

        QPushButton:pressed {
            background-color: #3d8b40;
        }

        QGroupBox {
            background-color: white;
            border: 2px solid #e0e0e0;
            border-radius: 8px;
            margin-top: 12px;
            padding: 10px;
            font-weight: bold;
            font-size: 12px;
        }

        QGroupBox::title {
            subcontrol-origin: margin;
            subcontrol-position: top left;
            padding: 5px 10px;
            color: #333;
            background-color: #f5f5f5;
            border-radius: 4px;
        }

        QLabel {
            color: #333;
            font-size: 11px;
            padding: 2px;
        }

        QProgressBar {
            border: 2px solid #e0e0e0;
            border-radius: 5px;
            text-align: center;
            height: 20px;
            background-color: #f0f0f0;
        }

        QProgressBar::chunk {
            background-color: #4CAF50;
            border-radius: 3px;
        }

        QPlainTextEdit {
            background-color: #ffffff;
            border: 2px solid #e0e0e0;
            border-radius: 6px;
            padding: 8px;
            font-family: 'Consolas', 'Courier New', monospace;
            font-size: 10px;
            color: #333;
        }
    )";

    setStyleSheet(mainStyle);

    // Estilos específicos para botones globales
    d->ui.btnStart->setStyleSheet("QPushButton { background-color: #2196F3; } QPushButton:hover { background-color: #1976D2; }");
    d->ui.btnPause->setStyleSheet("QPushButton { background-color: #FF9800; } QPushButton:hover { background-color: #F57C00; }");
    d->ui.btnStop->setStyleSheet("QPushButton { background-color: #f44336; } QPushButton:hover { background-color: #d32f2f; }");

    // Estilos para botones individuales de cada estación
    auto styleStationButtons = [](QPushButton* start, QPushButton* pause, QPushButton* stop) {
        start->setStyleSheet("QPushButton { background-color: #4CAF50; font-size: 9px; padding: 4px 8px; } QPushButton:hover { background-color: #45a049; }");
        pause->setStyleSheet("QPushButton { background-color: #FFC107; font-size: 9px; padding: 4px 8px; } QPushButton:hover { background-color: #FFB300; }");
        stop->setStyleSheet("QPushButton { background-color: #F44336; font-size: 9px; padding: 4px 8px; } QPushButton:hover { background-color: #E53935; }");
    };

    styleStationButtons(d->ui.btnAsmStart, d->ui.btnAsmPause, d->ui.btnAsmStop);
    styleStationButtons(d->ui.btnTesStart, d->ui.btnTesPause, d->ui.btnTesStop);
    styleStationButtons(d->ui.btnQCStart, d->ui.btnQCPause, d->ui.btnQCStop);
    styleStationButtons(d->ui.btnPacStart, d->ui.btnPacPause, d->ui.btnPacStop);
    styleStationButtons(d->ui.btnShipStart, d->ui.btnShipPause, d->ui.btnShipStop);
}

void MainWindow::reorganizeLayout()
{
    // Este método se llamará después de setupCharts para reorganizar
    // Por ahora lo dejamos vacío, la reorganización se hace en setupCharts
}

void MainWindow::changeSpeedMode(int index)
{
    switch (index) {

    case 0: // Fast
        Config::assemblerDelay = 150;
        Config::testerDelay    = 200;
        Config::qcDelay        = 200;
        Config::packerDelay    = 150;
        Config::shipDelay      = 100;
        break;

    case 1: // Normal
        Config::assemblerDelay = 500;
        Config::testerDelay    = 700;
        Config::qcDelay        = 600;
        Config::packerDelay    = 500;
        Config::shipDelay      = 400;
        break;

    case 2: // Slow
        Config::assemblerDelay = 900;
        Config::testerDelay    = 1200;
        Config::qcDelay        = 1000;
        Config::packerDelay    = 900;
        Config::shipDelay      = 800;
        break;
    }
}


