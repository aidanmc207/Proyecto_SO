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
