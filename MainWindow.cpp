#include "MainWindow.h"
#include "ProductionController.h"
#include <QComboBox>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QPlainTextEdit>
#include <QTableWidget>
#include <QStatusBar>
#include <QTableWidgetItem>
#include "ui_mainwindow.h"

class MainWindow::Impl {
public:
    Ui::MainWindow ui;
    ProductionController* controller = nullptr;
};

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), d(new Impl) {
    d->ui.setupUi(this);
    d->ui.tblThreads->setColumnCount(2);

    d->controller = new ProductionController(this);

    connect(this, &MainWindow::startProduction, d->controller, &ProductionController::start);
    connect(this, &MainWindow::pauseProduction, d->controller, &ProductionController::pause);
    connect(this, &MainWindow::stopProduction,  d->controller, &ProductionController::stop);

    connect(d->controller, &ProductionController::stationUpdated, this, &MainWindow::updateStation);
    connect(d->controller, &ProductionController::logLine, this, &MainWindow::appendLog);
    connect(d->controller, &ProductionController::threadList, this, &MainWindow::refreshThreadList);

    connect(d->ui.btnStart, &QPushButton::clicked, this, [this]{ emit startProduction(); });
    connect(d->ui.btnPause, &QPushButton::clicked, this, [this]{ emit pauseProduction(); });
    connect(d->ui.btnStop,  &QPushButton::clicked, this, [this]{ emit stopProduction();  });
}

MainWindow::~MainWindow(){ delete d; }

void MainWindow::updateStation(const QString& s, const QString& st, int prog){
    if(s=="Assembler"){ d->ui.lblAsmState->setText(st); d->ui.barAsm->setValue(prog); }
    else if(s=="Tester"){ d->ui.lblTesState->setText(st); d->ui.barTes->setValue(prog); }
    else if(s=="Packer"){ d->ui.lblPacState->setText(st); d->ui.barPac->setValue(prog); }
    statusBar()->showMessage(QString("%1: %2").arg(s, st), 2000);
}

void MainWindow::appendLog(const QString& line){ d->ui.txtLogs->appendPlainText(line); }

void MainWindow::refreshThreadList(const QStringList& threads){
    d->ui.tblThreads->clearContents();
    d->ui.tblThreads->setRowCount(threads.size());
    for(int i=0;i<threads.size();++i){
        d->ui.tblThreads->setItem(i,0,new QTableWidgetItem(QString("T%1").arg(i)));
        d->ui.tblThreads->setItem(i,1,new QTableWidgetItem(threads[i]));
    }
}
