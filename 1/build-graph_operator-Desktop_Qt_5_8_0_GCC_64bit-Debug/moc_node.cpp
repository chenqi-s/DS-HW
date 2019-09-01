/****************************************************************************
** Meta object code from reading C++ file 'node.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graph_operator2/relarankgraph/node.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'node.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_relarank__Node_t {
    QByteArrayData data[19];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_relarank__Node_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_relarank__Node_t qt_meta_stringdata_relarank__Node = {
    {
QT_MOC_LITERAL(0, 0, 14), // "relarank::Node"
QT_MOC_LITERAL(1, 15, 13), // "nodeActivated"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "nodeRenamed"
QT_MOC_LITERAL(4, 42, 4), // "name"
QT_MOC_LITERAL(5, 47, 16), // "removalRequested"
QT_MOC_LITERAL(6, 64, 14), // "inputConnected"
QT_MOC_LITERAL(7, 79, 5), // "Plug*"
QT_MOC_LITERAL(8, 85, 7), // "myInput"
QT_MOC_LITERAL(9, 93, 11), // "otherOutput"
QT_MOC_LITERAL(10, 105, 15), // "outputConnected"
QT_MOC_LITERAL(11, 121, 8), // "myOutput"
QT_MOC_LITERAL(12, 130, 10), // "otherInput"
QT_MOC_LITERAL(13, 141, 17), // "inputDisconnected"
QT_MOC_LITERAL(14, 159, 18), // "outputDisconnected"
QT_MOC_LITERAL(15, 178, 22), // "hasCompletelyCollapsed"
QT_MOC_LITERAL(16, 201, 19), // "aboutToExpandAfresh"
QT_MOC_LITERAL(17, 221, 14), // "outgoingSpread"
QT_MOC_LITERAL(18, 236, 14) // "incomingSpread"

    },
    "relarank::Node\0nodeActivated\0\0nodeRenamed\0"
    "name\0removalRequested\0inputConnected\0"
    "Plug*\0myInput\0otherOutput\0outputConnected\0"
    "myOutput\0otherInput\0inputDisconnected\0"
    "outputDisconnected\0hasCompletelyCollapsed\0"
    "aboutToExpandAfresh\0outgoingSpread\0"
    "incomingSpread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_relarank__Node[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       5,    0,   63,    2, 0x06 /* Public */,
       6,    2,   64,    2, 0x06 /* Public */,
      10,    2,   69,    2, 0x06 /* Public */,
      13,    2,   74,    2, 0x06 /* Public */,
      14,    2,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,   84,    2, 0x08 /* Private */,
      16,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,   11,   12,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,   11,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      17, QMetaType::QReal, 0x00095003,
      18, QMetaType::QReal, 0x00095003,

       0        // eod
};

void relarank::Node::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Node *_t = static_cast<Node *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nodeActivated(); break;
        case 1: _t->nodeRenamed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->removalRequested(); break;
        case 3: _t->inputConnected((*reinterpret_cast< Plug*(*)>(_a[1])),(*reinterpret_cast< Plug*(*)>(_a[2]))); break;
        case 4: _t->outputConnected((*reinterpret_cast< Plug*(*)>(_a[1])),(*reinterpret_cast< Plug*(*)>(_a[2]))); break;
        case 5: _t->inputDisconnected((*reinterpret_cast< Plug*(*)>(_a[1])),(*reinterpret_cast< Plug*(*)>(_a[2]))); break;
        case 6: _t->outputDisconnected((*reinterpret_cast< Plug*(*)>(_a[1])),(*reinterpret_cast< Plug*(*)>(_a[2]))); break;
        case 7: _t->hasCompletelyCollapsed(); break;
        case 8: _t->aboutToExpandAfresh(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Node::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node::nodeActivated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Node::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node::nodeRenamed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Node::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node::removalRequested)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Node::*_t)(Plug * , Plug * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node::inputConnected)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Node::*_t)(Plug * , Plug * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node::outputConnected)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Node::*_t)(Plug * , Plug * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node::inputDisconnected)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Node::*_t)(Plug * , Plug * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node::outputDisconnected)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Node *_t = static_cast<Node *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->m_outgoingExpansionFactor; break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->m_incomingExpansionFactor; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Node *_t = static_cast<Node *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->updateOutgoingSpread(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->updateIncomingSpread(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject relarank::Node::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_relarank__Node.data,
      qt_meta_data_relarank__Node,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *relarank::Node::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *relarank::Node::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_relarank__Node.stringdata0))
        return static_cast<void*>(const_cast< Node*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int relarank::Node::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void relarank::Node::nodeActivated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void relarank::Node::nodeRenamed(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void relarank::Node::removalRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void relarank::Node::inputConnected(Plug * _t1, Plug * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void relarank::Node::outputConnected(Plug * _t1, Plug * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void relarank::Node::inputDisconnected(Plug * _t1, Plug * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void relarank::Node::outputDisconnected(Plug * _t1, Plug * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
