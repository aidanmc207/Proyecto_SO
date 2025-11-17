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
    if (station.startsWith("Assembler")) {
        d->ui.lblAsmState->setText(state);
        d->ui.barAsm->setValue(queueSize);
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

    statusBar()->showMessage(QString("%1: %2").arg(station, state), 2000);
}

//STATS
void MainWindow::updateStats(const QString& station,
                             long processed,
                             int queueSize)
{
    if (station.startsWith("Assembler")) {//uso starts with por los dos assembler
        d->ui.lblAsmProcessed->setText(QString::number(processed));
        d->ui.barAsm->setValue(queueSize);
    }
    else if (station == "Tester") {
        d->ui.lblTesProcessed->setText(QString::number(processed));
        d->ui.barTes->setValue(queueSize);
    }
    else if (station == "QualityControl") {
        d->ui.lblQCProcessed->setText(QString::number(processed));
        d->ui.barQC->setValue(queueSize);
    }
    else if (station == "Packer") {
        d->ui.lblPacProcessed->setText(QString::number(processed));
        d->ui.barPac->setValue(queueSize);
    }

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
