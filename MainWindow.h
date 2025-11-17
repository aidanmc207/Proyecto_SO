#pragma once
#include <QMainWindow>
#include <QPainter>
#include <QWidget>

class ProductionController;
class StatsMonitor;

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
    void updateCharts(); // Actualizar gráficos en tiempo real
    void changeSpeedMode(int index);

private:
    void setupCharts(); // Inicializar los gráficos
    void exportChartData(); // Exportar datos a CSV
    void setupModernStyles(); // Aplicar estilos modernos
    void reorganizeLayout(); // Reorganizar en dos columnas

    class Impl; Impl* d;

    // Widget personalizado para el gráfico
    class ChartWidget;
    ChartWidget* m_chartWidget = nullptr;
};



