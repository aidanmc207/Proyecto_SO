
#include "ProductionController.h"
#include "ProductionLine.h"
#include "Logger.h"
#include "StatsMonitor.h"
#include "CleanUpService.h"
#include "Assembler.h"
#include "Tester.h"
#include "Packer.h"
#include "Product.h"

ProductionController::ProductionController(QObject* parent): QObject(parent){ init(); }

void ProductionController::init(){
    m_line = new ProductionLine(this);
    m_logger = new Logger(this);
    m_stats  = new StatsMonitor(this);
    m_cleaner= new CleanUpService(this);

    auto* asmbl = new Assembler("Assembler", this);
    auto* test  = new Tester("Tester", this);
    auto* pack  = new Packer("Packer", this);

    m_line->addStation(asmbl);
    m_line->addStation(test);
    m_line->addStation(pack);

    QObject::connect(m_line, &ProductionLine::stationUpdated, this, &ProductionController::stationUpdated);
    QObject::connect(m_line, &ProductionLine::log, this, &ProductionController::logLine);
}

void ProductionController::start(){
    static long gid=1;
    for(int i=0;i<20;++i){ Product p; p.id=gid++; m_line->firstBuffer()->push(p); }
    m_line->start(); emit logLine("Controller: start()");
}
void ProductionController::pause(){ m_line->pause(); emit logLine("Controller: pause()"); }
void ProductionController::stop(){ m_line->stop(); emit logLine("Controller: stop()"); }
