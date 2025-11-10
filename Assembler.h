
#pragma once
#include "WorkStation.h"
class Assembler : public WorkStation { Q_OBJECT
public: using WorkStation::WorkStation; protected: void process(Product& p) override { QThread::msleep(200); p.advance(); } };
