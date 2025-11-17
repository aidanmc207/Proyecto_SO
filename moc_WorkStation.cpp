/****************************************************************************
** Meta object code from reading C++ file 'WorkStation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "WorkStation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WorkStation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WorkStation_t {
    QByteArrayData data[17];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkStation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkStation_t qt_meta_stringdata_WorkStation = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WorkStation"
QT_MOC_LITERAL(1, 12, 12), // "statsUpdated"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "name"
QT_MOC_LITERAL(4, 31, 9), // "processed"
QT_MOC_LITERAL(5, 41, 9), // "queueSize"
QT_MOC_LITERAL(6, 51, 7), // "reworks"
QT_MOC_LITERAL(7, 59, 14), // "stationUpdated"
QT_MOC_LITERAL(8, 74, 5), // "state"
QT_MOC_LITERAL(9, 80, 3), // "log"
QT_MOC_LITERAL(10, 84, 4), // "line"
QT_MOC_LITERAL(11, 89, 8), // "consumed"
QT_MOC_LITERAL(12, 98, 11), // "stationName"
QT_MOC_LITERAL(13, 110, 5), // "start"
QT_MOC_LITERAL(14, 116, 5), // "pause"
QT_MOC_LITERAL(15, 122, 4), // "stop"
QT_MOC_LITERAL(16, 127, 7) // "runLoop"

    },
    "WorkStation\0statsUpdated\0\0name\0processed\0"
    "queueSize\0reworks\0stationUpdated\0state\0"
    "log\0line\0consumed\0stationName\0start\0"
    "pause\0stop\0runLoop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkStation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   54,    2, 0x06 /* Public */,
       7,    3,   63,    2, 0x06 /* Public */,
       9,    1,   70,    2, 0x06 /* Public */,
      11,    1,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   76,    2, 0x0a /* Public */,
      14,    0,   77,    2, 0x0a /* Public */,
      15,    0,   78,    2, 0x0a /* Public */,
      16,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Long, QMetaType::Int, QMetaType::Long,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    8,    5,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WorkStation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WorkStation *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->statsUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< long(*)>(_a[4]))); break;
        case 1: _t->stationUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->log((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->consumed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->start(); break;
        case 5: _t->pause(); break;
        case 6: _t->stop(); break;
        case 7: _t->runLoop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WorkStation::*)(const QString & , long , int , long );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkStation::statsUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WorkStation::*)(const QString & , const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkStation::stationUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WorkStation::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkStation::log)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WorkStation::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkStation::consumed)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WorkStation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_WorkStation.data,
    qt_meta_data_WorkStation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WorkStation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkStation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WorkStation.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WorkStation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void WorkStation::statsUpdated(const QString & _t1, long _t2, int _t3, long _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WorkStation::stationUpdated(const QString & _t1, const QString & _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WorkStation::log(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WorkStation::consumed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
