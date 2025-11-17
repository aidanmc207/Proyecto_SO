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

    // Señales para controles individuales de estaciones
    void startStation(const QString& station);
    void pauseStation(const QString& station);
    void stopStation(const QString& station);

public slots:
    void updateStation(const QString& station, const QString& state, int progress);
    void appendLog(const QString& line);
    void updateStats(const QString& name, long processed, int queue,long rework);
    void updateGlobalRework();
    void changeSpeedMode(int index);

private:
    class Impl; Impl* d;
};



