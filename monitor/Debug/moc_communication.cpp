/****************************************************************************
** Meta object code from reading C++ file 'communication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../communication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Communication_t {
    QByteArrayData data[12];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Communication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Communication_t qt_meta_stringdata_Communication = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Communication"
QT_MOC_LITERAL(1, 14, 15), // "signal_commType"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "CommSet::CommType"
QT_MOC_LITERAL(4, 49, 4), // "type"
QT_MOC_LITERAL(5, 54, 16), // "signal_commState"
QT_MOC_LITERAL(6, 71, 18), // "CommSet::CommState"
QT_MOC_LITERAL(7, 90, 5), // "state"
QT_MOC_LITERAL(8, 96, 18), // "signal_readValueId"
QT_MOC_LITERAL(9, 115, 2), // "id"
QT_MOC_LITERAL(10, 118, 18), // "signal_readStateId"
QT_MOC_LITERAL(11, 137, 12) // "slot_setComm"

    },
    "Communication\0signal_commType\0\0"
    "CommSet::CommType\0type\0signal_commState\0"
    "CommSet::CommState\0state\0signal_readValueId\0"
    "id\0signal_readStateId\0slot_setComm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Communication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       8,    1,   45,    2, 0x06 /* Public */,
      10,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Communication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Communication *_t = static_cast<Communication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_commType((*reinterpret_cast< CommSet::CommType(*)>(_a[1]))); break;
        case 1: _t->signal_commState((*reinterpret_cast< CommSet::CommState(*)>(_a[1]))); break;
        case 2: _t->signal_readValueId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signal_readStateId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slot_setComm(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Communication::*_t)(CommSet::CommType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::signal_commType)) {
                *result = 0;
            }
        }
        {
            typedef void (Communication::*_t)(CommSet::CommState );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::signal_commState)) {
                *result = 1;
            }
        }
        {
            typedef void (Communication::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::signal_readValueId)) {
                *result = 2;
            }
        }
        {
            typedef void (Communication::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communication::signal_readStateId)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Communication::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Communication.data,
      qt_meta_data_Communication,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Communication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Communication::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Communication.stringdata0))
        return static_cast<void*>(const_cast< Communication*>(this));
    return QThread::qt_metacast(_clname);
}

int Communication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Communication::signal_commType(CommSet::CommType _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Communication::signal_commState(CommSet::CommState _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Communication::signal_readValueId(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Communication::signal_readStateId(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
