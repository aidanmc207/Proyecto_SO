#pragma once
#include <QString>

enum class ProductState { New, Assembled, Tested, Packed };

struct Product {
    long id = 0;
    QString type = "Blender";
    ProductState state = ProductState::New;

    bool isStopSignal = false;      // <--- NUEVO

    void advance(){
        if(state==ProductState::New) state=ProductState::Assembled;
        else if(state==ProductState::Assembled) state=ProductState::Tested;
        else if(state==ProductState::Tested) state=ProductState::Packed;
    }
    QString show() const { return QString("#%1 %2").arg(id).arg(type); }
};
