#pragma once
#include "WorkStation.h"

class PipeManager;

class QualityControl : public WorkStation
{
    Q_OBJECT
public:
    explicit QualityControl(const QString& name);

    void setPipeManager(PipeManager* pipe) { m_pipe = pipe; }

protected:
    void process(Product& p) override;

private:
    PipeManager* m_pipe = nullptr;
};
