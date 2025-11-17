#include "firstView.h"
#include "ui_firstView.h"

#include "MainWindow.h"
#include "LogWindow.h"
#include "StatsWindow.h"

FirstView::FirstView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FirstView)
{
    ui->setupUi(this);

    connect(ui->btnProduction, &QPushButton::clicked,
            this, &FirstView::openProduction);

    connect(ui->btnLogs, &QPushButton::clicked,
            this, &FirstView::openLogs);

    // connect(ui->btnStats, &QPushButton::clicked,
    //         this, &FirstView::openStats);
}

FirstView::~FirstView()
{
    delete ui;
}

void FirstView::openProduction()
{
    if (!productionWin)
        productionWin = new MainWindow();

    productionWin->show();
    productionWin->raise();
}

void FirstView::openLogs()
{
    if (!logWin) {
        logWin = new LogWindow();
        //senal de retorno
        connect(logWin, &LogWindow::returnToFirstView,
                this, [this]() {
                    logWin->hide();
                    this->show();
                    this->raise();
                });
    }

    this->hide();     // ocultar
    logWin->show();
    logWin->raise();
}




