/****************************************************************************
** Meta object code from reading C++ file 'giswnd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../giswnd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'giswnd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GisWnd_t {
    QByteArrayData data[9];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GisWnd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GisWnd_t qt_meta_stringdata_GisWnd = {
    {
QT_MOC_LITERAL(0, 0, 6), // "GisWnd"
QT_MOC_LITERAL(1, 7, 19), // "slot_mouseLeftPress"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "QMouseEvent"
QT_MOC_LITERAL(4, 40, 5), // "event"
QT_MOC_LITERAL(5, 46, 20), // "slot_mouseRightPress"
QT_MOC_LITERAL(6, 67, 14), // "slot_mouseMove"
QT_MOC_LITERAL(7, 82, 15), // "slot_RefreshPos"
QT_MOC_LITERAL(8, 98, 21) // "slot_clearMeasureInfo"

    },
    "GisWnd\0slot_mouseLeftPress\0\0QMouseEvent\0"
    "event\0slot_mouseRightPress\0slot_mouseMove\0"
    "slot_RefreshPos\0slot_clearMeasureInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GisWnd[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,
       7,    0,   48,    2, 0x0a /* Public */,
       8,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GisWnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GisWnd *_t = static_cast<GisWnd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_mouseLeftPress((*reinterpret_cast< QMouseEvent(*)>(_a[1]))); break;
        case 1: _t->slot_mouseRightPress((*reinterpret_cast< QMouseEvent(*)>(_a[1]))); break;
        case 2: _t->slot_mouseMove((*reinterpret_cast< QMouseEvent(*)>(_a[1]))); break;
        case 3: _t->slot_RefreshPos(); break;
        case 4: _t->slot_clearMeasureInfo(); break;
        default: ;
        }
    }
}

const QMetaObject GisWnd::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GisWnd.data,
      qt_meta_data_GisWnd,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GisWnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GisWnd::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GisWnd.stringdata0))
        return static_cast<void*>(const_cast< GisWnd*>(this));
    return QWidget::qt_metacast(_clname);
}

int GisWnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE