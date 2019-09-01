/****************************************************************************
** Meta object code from reading C++ file 'nodectrl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graph_operator2/nodectrl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nodectrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NodeCtrl_t {
    QByteArrayData data[12];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NodeCtrl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NodeCtrl_t qt_meta_stringdata_NodeCtrl = {
    {
QT_MOC_LITERAL(0, 0, 8), // "NodeCtrl"
QT_MOC_LITERAL(1, 9, 6), // "remove"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 14), // "inputConnected"
QT_MOC_LITERAL(4, 32, 20), // "relarank::PlugHandle"
QT_MOC_LITERAL(5, 53, 7), // "myInput"
QT_MOC_LITERAL(6, 61, 11), // "otherOutput"
QT_MOC_LITERAL(7, 73, 15), // "outputConnected"
QT_MOC_LITERAL(8, 89, 8), // "myOutput"
QT_MOC_LITERAL(9, 98, 10), // "otherInput"
QT_MOC_LITERAL(10, 109, 17), // "inputDisconnected"
QT_MOC_LITERAL(11, 127, 18) // "outputDisconnected"

    },
    "NodeCtrl\0remove\0\0inputConnected\0"
    "relarank::PlugHandle\0myInput\0otherOutput\0"
    "outputConnected\0myOutput\0otherInput\0"
    "inputDisconnected\0outputDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NodeCtrl[] = {

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
       1,    0,   39,    2, 0x0a /* Public */,
       3,    2,   40,    2, 0x08 /* Private */,
       7,    2,   45,    2, 0x08 /* Private */,
      10,    2,   50,    2, 0x08 /* Private */,
      11,    2,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    8,    9,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    8,    9,

       0        // eod
};

void NodeCtrl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NodeCtrl *_t = static_cast<NodeCtrl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->remove();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->inputConnected((*reinterpret_cast< relarank::PlugHandle(*)>(_a[1])),(*reinterpret_cast< relarank::PlugHandle(*)>(_a[2]))); break;
        case 2: _t->outputConnected((*reinterpret_cast< relarank::PlugHandle(*)>(_a[1])),(*reinterpret_cast< relarank::PlugHandle(*)>(_a[2]))); break;
        case 3: _t->inputDisconnected((*reinterpret_cast< relarank::PlugHandle(*)>(_a[1])),(*reinterpret_cast< relarank::PlugHandle(*)>(_a[2]))); break;
        case 4: _t->outputDisconnected((*reinterpret_cast< relarank::PlugHandle(*)>(_a[1])),(*reinterpret_cast< relarank::PlugHandle(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject NodeCtrl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NodeCtrl.data,
      qt_meta_data_NodeCtrl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NodeCtrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NodeCtrl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NodeCtrl.stringdata0))
        return static_cast<void*>(const_cast< NodeCtrl*>(this));
    return QObject::qt_metacast(_clname);
}

int NodeCtrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
