#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include <QWidget>
#include <QLCDNumber>
#include <QLabel>
#include <QTimer>
#include <QMap>

class ProductionLine;   // forward declaration
class WorkStation;

namespace Ui {
class StatsWindow;
}

class StatsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StatsWindow(ProductionLine* line, QWidget *parent = nullptr);
    ~StatsWindow();

private slots:
    void refreshStats();   // Se ejecuta cada 300 ms

private:
    Ui::StatsWindow *ui;
    ProductionLine* m_line;
    QTimer* m_timer;

    struct StationWidgets {
        QLabel*      lblName;
        QLCDNumber*  lcdProcessed;
        QLCDNumber*  lcdBuffer;
    };

    // Mapeo: nombreEstacion → filas del UI
    QMap<QString, StationWidgets> m_stationWidgets;

    void setupStationMap();     // Enlaza UI con estaciones
};

#endif // STATSWINDOW_H

