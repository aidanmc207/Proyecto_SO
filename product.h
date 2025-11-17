#pragma once
#include <QString>
#include <QStringList>
#include <cstring>

//estados del prrod
enum class ProductState {
    New,
    Assembled,
    Tested,
    Packed,
    Rework
};
inline QString productStateToString(ProductState s) {
    switch (s) {
    case ProductState::New:       return "New";
    case ProductState::Assembled: return "Assembled";
    case ProductState::Tested:    return "Tested";
    case ProductState::Packed:    return "Packed";
    case ProductState::Rework:    return "Rework";
    }
    return "Unknown";
}


extern QStringList productTypes;


struct Product {
    long id = 0;
    QString type;
    ProductState state = ProductState::New;

    void advance() {
        if (state == ProductState::New)
            state = ProductState::Assembled;

        else if (state == ProductState::Assembled)
            state = ProductState::Tested;

        else if (state == ProductState::Tested)
            state = ProductState::Packed;

        else if (state == ProductState::Rework)
            state = ProductState::Assembled;  // Rework vuelve al inicio
    }


    QString show() const {
        return QString("#%1 (%2 | %3)")
            .arg(id)
            .arg(type)
            .arg(productStateToString(state));
    }



};


// #pragma pack(push, 1)
// struct ProductPipeData {
//     long id;
//     int  state;
//     char type[32];//stringg
// };
// #pragma pack(pop)


// //deconstruye el producto para enviar por el pipe
// inline ProductPipeData toPipeData(const Product& p)
// {
//     ProductPipeData d;
//     d.id = p.id;
//     d.state = (int)p.state;

//     memset(d.type, 0, sizeof(d.type));
//     QByteArray arr = p.type.toUtf8();
//     strncpy(d.type, arr.constData(), sizeof(d.type) - 1);

//     return d;
// }
// //para armar el producto a partir del pipe
// inline Product fromPipeData(const ProductPipeData& d)
// {
//     Product p;
//     p.id = d.id;
//     p.state = (ProductState)d.state;
//     p.type = QString::fromUtf8(d.type);
//     return p;
// }

struct ProductPipeData {
    long id;
    int  typeIndex;
    int  state;
};

inline ProductPipeData toPipeData(const Product& p)
{
    ProductPipeData d;
    d.id    = p.id;
    d.state = static_cast<int>(p.state);

    int idx = productTypes.indexOf(p.type);
    d.typeIndex = idx; // -1 si no lo encuentra
    return d;
}

inline Product fromPipeData(const ProductPipeData& d)
{
    Product p;
    p.id    = d.id;
    p.state = static_cast<ProductState>(d.state);

    if (d.typeIndex >= 0 && d.typeIndex < productTypes.size())
        p.type = productTypes[d.typeIndex];
    else
        p.type = "Unknown";

    return p;
}
