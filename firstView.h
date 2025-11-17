#pragma once

#include <QWidget>

class MainWindow;
class LogWindow;

namespace Ui {
class FirstView;
}

class FirstView : public QWidget
{
    Q_OBJECT

public:
    explicit FirstView(QWidget *parent = nullptr);
    ~FirstView();

private slots:
    void openProduction();
    void openLogs();
private:
    Ui::FirstView *ui;

    MainWindow* productionWin = nullptr;
    LogWindow* logWin = nullptr;
};

