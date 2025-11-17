#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QWidget>

namespace Ui {
class LogWindow;
}

class LogWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget* parent = nullptr);
    ~LogWindow();

    void appendLog(const QString& text);

signals:
    void returnToFirstView();

private slots:
    void onClear();
    void onExport();
    void onReturn();

private:
    void loadFromFile();

    Ui::LogWindow* ui;
};

#endif // LOGWINDOW_H
