/****************************************************************************
** Meta object code from reading C++ file 'nodehandle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graph_operator2/relarankgraph/nodehandle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nodehandle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_relarank__NodeHandle_t {
    QByteArrayData data[21];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_relarank__NodeHandle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_relarank__NodeHandle_t qt_meta_stringdata_relarank__NodeHandle = {
    {
QT_MOC_LITERAL(0, 0, 20), // "relarank::NodeHandle"
QT_MOC_LITERAL(1, 21, 13), // "nodeActivated"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "nodeRenamed"
QT_MOC_LITERAL(4, 48, 4), // "name"
QT_MOC_LITERAL(5, 53, 16), // "removalRequested"
QT_MOC_LITERAL(6, 70, 14), // "inputConnected"
QT_MOC_LITERAL(7, 85, 20), // "relarank::PlugHandle"
QT_MOC_LITERAL(8, 106, 7), // "myInput"
QT_MOC_LITERAL(9, 114, 11), // "otherOutput"
QT_MOC_LITERAL(10, 126, 15), // "outputConnected"
QT_MOC_LITERAL(11, 142, 8), // "myOutput"
QT_MOC_LITERAL(12, 151, 10), // "otherInput"
QT_MOC_LITERAL(13, 162, 17), // "inputDisconnected"
QT_MOC_LITERAL(14, 180, 18), // "outputDisconnected"
QT_MOC_LITERAL(15, 199, 18), // "passInputConnected"
QT_MOC_LITERAL(16, 218, 5), // "Plug*"
QT_MOC_LITERAL(17, 224, 19), // "passOutputConnected"
QT_MOC_LITERAL(18, 244, 21), // "passInputDisconnected"
QT_MOC_LITERAL(19, 266, 22), // "passOutputDisconnected"
QT_MOC_LITERAL(20, 289, 16) // "nodeWasDestroyed"

    },
    "relarank::NodeHandle\0nodeActivated\0\0"
    "nodeRenamed\0name\0removalRequested\0"
    "inputConnected\0relarank::PlugHandle\0"
    "myInput\0otherOutput\0outputConnected\0"
    "myOutput\0otherInput\0inputDisconnected\0"
    "outputDisconnected\0passInputConnected\0"
    "Plug*\0passOutputConnected\0"
    "passInputDisconnected\0passOutputDisconnected\0"
    "nodeWasDestroyed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_relarank__NodeHandle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,
       5,    0,   78,    2, 0x06 /* Public */,
       6,    2,   79,    2, 0x06 /* Public */,
      10,    2,   84,    2, 0x06 /* Public */,
      13,    2,   89,    2, 0x06 /* Public */,
      14,    2,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    2,   99,    2, 0x08 /* Private */,
      17,    2,  104,    2, 0x08 /* Private */,
      18,    2,  109,    2, 0x08 /* Private */,
      19,    2,  114,    2, 0x08 /* Private */,
      20,    0,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,   11,   12,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,   11,   12,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16,    8,    9,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16,   11,   12,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16,    8,    9,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16,   11,   12,
    QMetaType::Void,

       0        // eod
};

void relarank::NodeHandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NodeHandle *_t = static_cast<NodeHandle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nodeActivated(); break;
        case 1: _t->nodeRenamed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->removalRequested(); break;
        case 3: _t->inputConnected((*reinterpret_cast< relarank::PlugHandle(*)>(_a[1])),(*reinterpret_cast< relarank::PlugHandle(*)>(_a[2]))); break;
        case 4: _t->outputConnected((*reinterpret_cast< relarank::PlugHandle(*)>(_a[1])),(*reinterpret_cast< relarank::PlugHandle(*)>(_a[2]))); break;
        case 5: _t->inputDisconnected((*reinterpret_cast< relarank::PlugHandle(*)>(_a[1])),(*reinterpret_cast< relarank::PlugHandle(*)>(_a[2]))); break;
        case 6: _t->outputDisconnected((*reinterpret_cast< relarank::PlugHandle(*)>(_a[1])),(*reinterpret_cast< relarank::PlugHandle(*)>(_a[2]))); break;
        case 7: _t->passInputConnected((*reinterpret_cast< Plug*(*)>(_a[1])),(*reinterpret_cast< Plug*(*)>(_a[2]))); break;
        case 8: _t->passOutputConnected((*reinterpret_cast< Plug*(*)>(_a[1])),(*reinterpret_cast< Plug*(*)>(_a[2]))); break;
        case 9: _t->passInputDisconnected((*reinterpret_cast< Plug*(*)>(_a[1])),(*reinterpret_cast< Plug*(*)>(_a[2]))); break;
        case 10: _t->passOutputDisconnected((*reinterpret_cast< Plug*(*)>(_a[1])),(*reinterpret_cast< Plug*(*)>(_a[2]))); break;
        case 11: _t->nodeWasDestroyed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NodeHandle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NodeHandle::nodeActivated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NodeHandle::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NodeHandle::nodeRenamed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NodeHandle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NodeHandle::removalRequested)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NodeHandle::*_t)(relarank::PlugHandle , relarank::PlugHandle );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NodeHandle::inputConnected)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (NodeHandle::*_t)(relarank::PlugHandle , relarank::PlugHandle );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NodeHandle::outputConnected)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (NodeHandle::*_t)(relarank::PlugHandle , relarank::PlugHandle );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NodeHandle::inputDisconnected)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (NodeHandle::*_t)(relarank::PlugHandle , relarank::PlugHandle );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NodeHandle::outputDisconnected)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject relarank::NodeHandle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_relarank__NodeHandle.data,
      qt_meta_data_relarank__NodeHandle,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *relarank::NodeHandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *relarank::NodeHandle::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_relarank__NodeHandle.stringdata0))
        return static_cast<void*>(const_cast< NodeHandle*>(this));
    return QObject::qt_metacast(_clname);
}

int relarank::NodeHandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void relarank::NodeHandle::nodeActivated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void relarank::NodeHandle::nodeRenamed(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void relarank::NodeHandle::removalRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void relarank::NodeHandle::inputConnected(relarank::PlugHandle _t1, relarank::PlugHandle _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void relarank::NodeHandle::outputConnected(relarank::PlugHandle _t1, relarank::PlugHandle _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void relarank::NodeHandle::inputDisconnected(relarank::PlugHandle _t1, relarank::PlugHandle _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void relarank::NodeHandle::outputDisconnected(relarank::PlugHandle _t1, relarank::PlugHandle _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
