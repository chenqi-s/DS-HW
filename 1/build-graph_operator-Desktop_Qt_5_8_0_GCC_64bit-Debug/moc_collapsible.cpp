/****************************************************************************
** Meta object code from reading C++ file 'collapsible.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graph_operator2/collapsible.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'collapsible.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Collapsible_t {
    QByteArrayData data[5];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Collapsible_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Collapsible_t qt_meta_stringdata_Collapsible = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Collapsible"
QT_MOC_LITERAL(1, 12, 11), // "updateTitle"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "title"
QT_MOC_LITERAL(4, 31, 14) // "toggleCollapse"

    },
    "Collapsible\0updateTitle\0\0title\0"
    "toggleCollapse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Collapsible[] = {

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
       1,    1,   29,    2, 0x0a /* Public */,
       1,    0,   32,    2, 0x2a /* Public | MethodCloned */,
       4,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Collapsible::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Collapsible *_t = static_cast<Collapsible *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->updateTitle(); break;
        case 2: _t->toggleCollapse(); break;
        default: ;
        }
    }
}

const QMetaObject Collapsible::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_Collapsible.data,
      qt_meta_data_Collapsible,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Collapsible::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Collapsible::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Collapsible.stringdata0))
        return static_cast<void*>(const_cast< Collapsible*>(this));
    return QFrame::qt_metacast(_clname);
}

int Collapsible::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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
