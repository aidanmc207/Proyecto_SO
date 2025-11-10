
#pragma once
#include "WorkStation.h"
class Tester : public WorkStation { Q_OBJECT
public: using WorkStation::WorkStation; protected: void process(Product& p) override { QThread::msleep(150); p.advance(); } };
