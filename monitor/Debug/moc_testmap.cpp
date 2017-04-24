/****************************************************************************
** Meta object code from reading C++ file 'testmap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../testmap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testmap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TestMap_t {
    QByteArrayData data[7];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestMap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestMap_t qt_meta_stringdata_TestMap = {
    {
QT_MOC_LITERAL(0, 0, 7), // "TestMap"
QT_MOC_LITERAL(1, 8, 13), // "signal_latLng"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "lat"
QT_MOC_LITERAL(4, 27, 3), // "lng"
QT_MOC_LITERAL(5, 31, 14), // "signal_clearWp"
QT_MOC_LITERAL(6, 46, 11) // "slot_latLng"

    },
    "TestMap\0signal_latLng\0\0lat\0lng\0"
    "signal_clearWp\0slot_latLng"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestMap[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void TestMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestMap *_t = static_cast<TestMap *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_latLng((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->signal_clearWp(); break;
        case 2: _t->slot_latLng(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TestMap::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TestMap::signal_latLng)) {
                *result = 0;
            }
        }
        {
            typedef void (TestMap::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TestMap::signal_clearWp)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject TestMap::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TestMap.data,
      qt_meta_data_TestMap,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TestMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestMap::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TestMap.stringdata0))
        return static_cast<void*>(const_cast< TestMap*>(this));
    return QDialog::qt_metacast(_clname);
}

int TestMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void TestMap::signal_latLng(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TestMap::signal_clearWp()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
