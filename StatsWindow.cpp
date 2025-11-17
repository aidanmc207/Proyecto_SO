#include "StatsWindow.h"
#include "ui_StatsWindow.h"

#include "ProductionLine.h"
#include "WorkStation.h"
#include "Buffer.h"

StatsWindow::StatsWindow(ProductionLine* line, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatsWindow)
    , m_line(line)
{
    ui->setupUi(this);

    setupStationMap();

    // refrescar cada 300ms
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout,
            this,      &StatsWindow::refreshStats);
    m_timer->start(300);
}

StatsWindow::~StatsWindow()
{
    delete ui;
}


void StatsWindow::setupStationMap()
{
    // ⚠ Asegurate que los nombres coinciden EXACTO con los del .ui
    m_stationWidgets["Assembler-1"] = {
        ui->stationName1,
        ui->lcdProcessed1,
        ui->lcdBuffer1
    };

    m_stationWidgets["Assembler-2"] = {
        ui->stationName2,
        ui->lcdProcessed2,
        ui->lcdBuffer2
    };

    m_stationWidgets["Tester"] = {
        ui->stationName3,
        ui->lcdProcessed3,
        ui->lcdBuffer3
    };

    m_stationWidgets["QualityControl"] = {
        ui->stationName4,
        ui->lcdProcessed4,
        ui->lcdBuffer4
    };

    m_stationWidgets["Packer"] = {
        ui->stationName5,
        ui->lcdProcessed5,
        ui->lcdBuffer5
    };

    m_stationWidgets["Shipping"] = {
        ui->stationName6,
        ui->lcdProcessed6,
        ui->lcdBuffer6
    };
}


void StatsWindow::refreshStats()
{
    if (!m_line) return;

    const auto stations = m_line->stations();

    for (WorkStation* ws : stations)
    {
        const QString name = ws->name();
        if (!m_stationWidgets.contains(name))
            continue;

        const auto& w = m_stationWidgets[name];

        w.lblName->setText(name);
        w.lcdProcessed->display(static_cast<int>(ws->processedCount()));

        Buffer<Product>* in  = ws->inputBuffer();
        Buffer<Product>* out = ws->outputBuffer();

        int bufCount = 0;
        if (in)  bufCount += static_cast<int>(in->size());
        if (out) bufCount += static_cast<int>(out->size());

        w.lcdBuffer->display(bufCount);
    }
}


