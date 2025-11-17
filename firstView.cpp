#include "firstView.h"
#include "ui_firstView.h"

#include "MainWindow.h"
#include "LogWindow.h"

FirstView::FirstView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FirstView)
{
    ui->setupUi(this);

    connect(ui->btnProduction, &QPushButton::clicked,
            this, &FirstView::openProduction);

    connect(ui->btnLogs, &QPushButton::clicked,
            this, &FirstView::openLogs);

    //css interno
    setStyleSheet(R"(
    QWidget {
        background-color: #f5f5f5;
        font-family: 'Segoe UI', 'Inter', 'Roboto', sans-serif;
        font-size: 11pt;
        color: #333;
    }

    QPlainTextEdit, QTextEdit {
        background-color: #ffffff;
        border: 2px solid #e0e0e0;
        border-radius: 6px;
        padding: 10px;
        font-family: 'JetBrains Mono', 'Consolas', 'Courier New', monospace;
        font-size: 10pt;
        color: #222;
    }

    QPushButton {
        background-color: #4CAF50;
        color: white;
        border: none;
        padding: 8px 14px;
        border-radius: 6px;
        font-weight: bold;
    }

    QPushButton:hover {
        background-color: #45a049;
    }

    QPushButton:pressed {
        background-color: #3d8b40;
    }

    #btnClear {
        background-color: #2196F3;
    }
    #btnClear:hover {
        background-color: #1976D2;
    }

    #btnExport {
        background-color: #FF9800;
    }
    #btnExport:hover {
        background-color: #FB8C00;
    }

    #returnBtn {
        background-color: #f44336;
    }
    #returnBtn:hover {
        background-color: #d32f2f;
    }
)");
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
    this->hide();
}

void FirstView::openLogs()
{
    if (!logWin) {
        logWin = new LogWindow();
        //senal de retorno
        connect(logWin, &LogWindow::returnToFirstView,
                this, [this]() {logWin->hide();this->show(); this->raise();
                });
    }

    this->hide();     // ocultar
    logWin->show();
    logWin->raise();
}




