/****************************************************************************
** Meta object code from reading C++ file 'ProductionController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ProductionController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProductionController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProductionController_t {
    QByteArrayData data[20];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProductionController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProductionController_t qt_meta_stringdata_ProductionController = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ProductionController"
QT_MOC_LITERAL(1, 21, 7), // "logLine"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "line"
QT_MOC_LITERAL(4, 35, 14), // "stationUpdated"
QT_MOC_LITERAL(5, 50, 4), // "name"
QT_MOC_LITERAL(6, 55, 5), // "state"
QT_MOC_LITERAL(7, 61, 9), // "queueSize"
QT_MOC_LITERAL(8, 71, 12), // "statsUpdated"
QT_MOC_LITERAL(9, 84, 7), // "station"
QT_MOC_LITERAL(10, 92, 9), // "processed"
QT_MOC_LITERAL(11, 102, 6), // "rework"
QT_MOC_LITERAL(12, 109, 5), // "start"
QT_MOC_LITERAL(13, 115, 5), // "pause"
QT_MOC_LITERAL(14, 121, 4), // "stop"
QT_MOC_LITERAL(15, 126, 12), // "startStation"
QT_MOC_LITERAL(16, 139, 11), // "stationName"
QT_MOC_LITERAL(17, 151, 12), // "pauseStation"
QT_MOC_LITERAL(18, 164, 11), // "stopStation"
QT_MOC_LITERAL(19, 176, 17) // "onStationConsumed"

    },
    "ProductionController\0logLine\0\0line\0"
    "stationUpdated\0name\0state\0queueSize\0"
    "statsUpdated\0station\0processed\0rework\0"
    "start\0pause\0stop\0startStation\0stationName\0"
    "pauseStation\0stopStation\0onStationConsumed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProductionController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    3,   67,    2, 0x06 /* Public */,
       8,    4,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   83,    2, 0x0a /* Public */,
      13,    0,   84,    2, 0x0a /* Public */,
      14,    0,   85,    2, 0x0a /* Public */,
      15,    1,   86,    2, 0x0a /* Public */,
      17,    1,   89,    2, 0x0a /* Public */,
      18,    1,   92,    2, 0x0a /* Public */,
      19,    1,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    5,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Long, QMetaType::Int, QMetaType::Long,    9,   10,    7,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void ProductionController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProductionController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->logLine((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->stationUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->statsUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< long(*)>(_a[4]))); break;
        case 3: _t->start(); break;
        case 4: _t->pause(); break;
        case 5: _t->stop(); break;
        case 6: _t->startStation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->pauseStation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->stopStation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->onStationConsumed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProductionController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductionController::logLine)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProductionController::*)(const QString & , const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductionController::stationUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ProductionController::*)(const QString & , long , int , long );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductionController::statsUpdated)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProductionController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ProductionController.data,
    qt_meta_data_ProductionController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProductionController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProductionController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProductionController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ProductionController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ProductionController::logLine(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProductionController::stationUpdated(const QString & _t1, const QString & _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProductionController::statsUpdated(const QString & _t1, long _t2, int _t3, long _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
