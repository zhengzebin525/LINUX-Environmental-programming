/****************************************************************************
** Meta object code from reading C++ file 'runwaterled.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "runwaterled.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'runwaterled.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RunWaterLED_t {
    QByteArrayData data[10];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RunWaterLED_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RunWaterLED_t qt_meta_stringdata_RunWaterLED = {
    {
QT_MOC_LITERAL(0, 0, 11), // "RunWaterLED"
QT_MOC_LITERAL(1, 12, 18), // "on_StartBt_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "on_EndBt_clicked"
QT_MOC_LITERAL(4, 49, 7), // "LedWork"
QT_MOC_LITERAL(5, 57, 5), // "LedOn"
QT_MOC_LITERAL(6, 63, 6), // "lednum"
QT_MOC_LITERAL(7, 70, 6), // "LedOff"
QT_MOC_LITERAL(8, 77, 8), // "Delay_ms"
QT_MOC_LITERAL(9, 86, 4) // "msec"

    },
    "RunWaterLED\0on_StartBt_clicked\0\0"
    "on_EndBt_clicked\0LedWork\0LedOn\0lednum\0"
    "LedOff\0Delay_ms\0msec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RunWaterLED[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
       8,    1,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void RunWaterLED::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RunWaterLED *_t = static_cast<RunWaterLED *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_StartBt_clicked(); break;
        case 1: _t->on_EndBt_clicked(); break;
        case 2: _t->LedWork(); break;
        case 3: _t->LedOn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->LedOff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->Delay_ms((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject RunWaterLED::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RunWaterLED.data,
      qt_meta_data_RunWaterLED,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RunWaterLED::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RunWaterLED::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RunWaterLED.stringdata0))
        return static_cast<void*>(const_cast< RunWaterLED*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RunWaterLED::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
