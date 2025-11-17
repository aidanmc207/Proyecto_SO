#include "LogWindow.h"
#include "ui_LogWindow.h"
#include <QFileDialog>
#include <QTextStream>

LogWindow::LogWindow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::LogWindow)
{
    ui->setupUi(this);
     loadFromFile();

    //Conectar botones
    connect(ui->btnClear,   &QPushButton::clicked, this, &LogWindow::onClear);
    connect(ui->btnExport,  &QPushButton::clicked, this, &LogWindow::onExport);
    connect(ui->returnBtn,  &QPushButton::clicked, this, &LogWindow::onReturn);
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

LogWindow::~LogWindow()
{
    delete ui;
}

void LogWindow::appendLog(const QString& text)
{
    ui->logTextEdit->append(text);   // <- ESTA ES LA ZONA DONDE SE VE EL LOG
}

void LogWindow::onClear()
{
    ui->logTextEdit->clear();
}
void LogWindow::loadFromFile()
{
    QFile file("runtime.log");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    ui->logTextEdit->setPlainText(in.readAll());
}
void LogWindow::onExport()
{
    QString filename = QFileDialog::getSaveFileName(
        this,
        "Guardar Log",
        "log.txt",
        "Text Files (*.txt)");

    if (filename.isEmpty())
        return;

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << ui->logTextEdit->toPlainText();
}

void LogWindow::onReturn()
{
    emit returnToFirstView();
    this->hide();
}
