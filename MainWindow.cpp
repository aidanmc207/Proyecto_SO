#include "MainWindow.h"
#include "ProductionController.h"
#include "ui_mainwindow.h"

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
    connect(d->ui.cmbSpeed, &QComboBox::currentIndexChanged,
            this, &MainWindow::changeSpeedMode);

}

MainWindow::~MainWindow()
{
    if (d->controller)
        d->controller->saveState();

    delete d;
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

