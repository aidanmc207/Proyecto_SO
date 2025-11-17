#pragma once
#include <QMainWindow>
class ProductionController;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent=nullptr);
    ~MainWindow();

signals:
    void startProduction();
    void pauseProduction();
    void stopProduction();

public slots:
    void updateStation(const QString& station, const QString& state, int progress);
    void appendLog(const QString& line);
    void updateStats(const QString& name, long processed, int queue);

private:
    class Impl; Impl* d;
};



