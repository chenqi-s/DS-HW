/****************************************************************************
** Meta object code from reading C++ file 'nodeproperties.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graph_operator2/nodeproperties.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nodeproperties.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NodeProperties_t {
    QByteArrayData data[7];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NodeProperties_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NodeProperties_t qt_meta_stringdata_NodeProperties = {
    {
QT_MOC_LITERAL(0, 0, 14), // "NodeProperties"
QT_MOC_LITERAL(1, 15, 10), // "renameNode"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "createNewPlug"
QT_MOC_LITERAL(4, 41, 10), // "addPlugRow"
QT_MOC_LITERAL(5, 52, 20), // "relarank::PlugHandle"
QT_MOC_LITERAL(6, 73, 4) // "plug"

    },
    "NodeProperties\0renameNode\0\0createNewPlug\0"
    "addPlugRow\0relarank::PlugHandle\0plug"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NodeProperties[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    1,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void NodeProperties::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NodeProperties *_t = static_cast<NodeProperties *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->renameNode(); break;
        case 1: _t->createNewPlug(); break;
        case 2: _t->addPlugRow((*reinterpret_cast< relarank::PlugHandle(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NodeProperties::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NodeProperties.data,
      qt_meta_data_NodeProperties,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NodeProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NodeProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NodeProperties.stringdata0))
        return static_cast<void*>(const_cast< NodeProperties*>(this));
    return QWidget::qt_metacast(_clname);
}

int NodeProperties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_PlugRow_t {
    QByteArrayData data[5];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlugRow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlugRow_t qt_meta_stringdata_PlugRow = {
    {
QT_MOC_LITERAL(0, 0, 7), // "PlugRow"
QT_MOC_LITERAL(1, 8, 10), // "renamePlug"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 19), // "togglePlugDirection"
QT_MOC_LITERAL(4, 40, 10) // "removePlug"

    },
    "PlugRow\0renamePlug\0\0togglePlugDirection\0"
    "removePlug"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlugRow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlugRow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlugRow *_t = static_cast<PlugRow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->renamePlug(); break;
        case 1: _t->togglePlugDirection(); break;
        case 2: _t->removePlug(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PlugRow::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PlugRow.data,
      qt_meta_data_PlugRow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlugRow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlugRow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlugRow.stringdata0))
        return static_cast<void*>(const_cast< PlugRow*>(this));
    return QObject::qt_metacast(_clname);
}

int PlugRow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
