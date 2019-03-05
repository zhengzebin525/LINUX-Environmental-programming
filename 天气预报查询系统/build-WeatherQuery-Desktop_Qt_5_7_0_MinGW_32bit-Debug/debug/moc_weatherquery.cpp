/****************************************************************************
** Meta object code from reading C++ file 'weatherquery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WeatherQuery/weatherquery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weatherquery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WeatherQuery_t {
    QByteArrayData data[13];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeatherQuery_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeatherQuery_t qt_meta_stringdata_WeatherQuery = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WeatherQuery"
QT_MOC_LITERAL(1, 13, 11), // "update_time"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "read_cjson"
QT_MOC_LITERAL(4, 37, 14), // "QNetworkReply*"
QT_MOC_LITERAL(5, 52, 5), // "repay"
QT_MOC_LITERAL(6, 58, 17), // "on_SkinBt_clicked"
QT_MOC_LITERAL(7, 76, 18), // "on_CheckBt_clicked"
QT_MOC_LITERAL(8, 95, 11), // "eventFilter"
QT_MOC_LITERAL(9, 107, 7), // "watched"
QT_MOC_LITERAL(10, 115, 7), // "QEvent*"
QT_MOC_LITERAL(11, 123, 5), // "event"
QT_MOC_LITERAL(12, 129, 18) // "on_CloseBt_clicked"

    },
    "WeatherQuery\0update_time\0\0read_cjson\0"
    "QNetworkReply*\0repay\0on_SkinBt_clicked\0"
    "on_CheckBt_clicked\0eventFilter\0watched\0"
    "QEvent*\0event\0on_CloseBt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherQuery[] = {

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
       3,    1,   45,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    2,   50,    2, 0x08 /* Private */,
      12,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 10,    9,   11,
    QMetaType::Void,

       0        // eod
};

void WeatherQuery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeatherQuery *_t = static_cast<WeatherQuery *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_time(); break;
        case 1: _t->read_cjson((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->on_SkinBt_clicked(); break;
        case 3: _t->on_CheckBt_clicked(); break;
        case 4: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->on_CloseBt_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject WeatherQuery::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_WeatherQuery.data,
      qt_meta_data_WeatherQuery,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WeatherQuery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherQuery::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherQuery.stringdata0))
        return static_cast<void*>(const_cast< WeatherQuery*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int WeatherQuery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
