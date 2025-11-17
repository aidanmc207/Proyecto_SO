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

    //botones
    connect(d->ui.btnStart, &QPushButton::clicked,
            this, [this]{ emit startProduction(); });

    connect(d->ui.btnPause, &QPushButton::clicked,
            this, [this]{ emit pauseProduction(); });

    connect(d->ui.btnStop, &QPushButton::clicked,
            this, [this]{ emit stopProduction(); });
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
    if (station == "Assembler-1") {
        d->ui.lblAsm1State ->setText(state);
        d->ui.barAsm1->setValue(queueSize);
    }
    else if (station == "Assembler-2") {
        d->ui.lblAsm2State->setText(state);
        d->ui.barAsm2->setValue(queueSize);
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
    else if(station=="Shipping"){
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
    else if (station=="Shipping"){
        d->ui.lblShipProcessed->setText(QString("Shipped: %1").arg(processed));
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

