
#pragma once
#include "WorkStation.h"
class Packer : public WorkStation { Q_OBJECT
public: using WorkStation::WorkStation; protected: void process(Product& p) override { QThread::msleep(120); p.advance(); } };
