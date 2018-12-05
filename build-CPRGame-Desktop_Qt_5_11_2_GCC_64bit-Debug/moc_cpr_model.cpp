/****************************************************************************
** Meta object code from reading C++ file 'cpr_model.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CPRGame/cpr_model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cpr_model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CPR_Model_t {
    QByteArrayData data[15];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CPR_Model_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CPR_Model_t qt_meta_stringdata_CPR_Model = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CPR_Model"
QT_MOC_LITERAL(1, 10, 21), // "changeStatusBoxSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "string"
QT_MOC_LITERAL(4, 40, 7), // "message"
QT_MOC_LITERAL(5, 48, 23), // "changeTutorialBoxSignal"
QT_MOC_LITERAL(6, 72, 17), // "gameOverWinSignal"
QT_MOC_LITERAL(7, 90, 18), // "gameOverLoseSignal"
QT_MOC_LITERAL(8, 109, 15), // "toggleAEDSignal"
QT_MOC_LITERAL(9, 125, 6), // "toggle"
QT_MOC_LITERAL(10, 132, 13), // "isMoveCorrect"
QT_MOC_LITERAL(11, 146, 9), // "isCorrect"
QT_MOC_LITERAL(12, 156, 15), // "actionPerformed"
QT_MOC_LITERAL(13, 172, 19), // "changeProModeStatus"
QT_MOC_LITERAL(14, 192, 7) // "newGame"

    },
    "CPR_Model\0changeStatusBoxSignal\0\0"
    "string\0message\0changeTutorialBoxSignal\0"
    "gameOverWinSignal\0gameOverLoseSignal\0"
    "toggleAEDSignal\0toggle\0isMoveCorrect\0"
    "isCorrect\0actionPerformed\0changeProModeStatus\0"
    "newGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CPR_Model[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       7,    1,   68,    2, 0x06 /* Public */,
       8,    1,   71,    2, 0x06 /* Public */,
      10,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   77,    2, 0x0a /* Public */,
      13,    1,   80,    2, 0x0a /* Public */,
      14,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void CPR_Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CPR_Model *_t = static_cast<CPR_Model *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeStatusBoxSignal((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->changeTutorialBoxSignal((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->gameOverWinSignal((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 3: _t->gameOverLoseSignal((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 4: _t->toggleAEDSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->isMoveCorrect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->actionPerformed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->changeProModeStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->newGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CPR_Model::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CPR_Model::changeStatusBoxSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CPR_Model::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CPR_Model::changeTutorialBoxSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CPR_Model::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CPR_Model::gameOverWinSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CPR_Model::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CPR_Model::gameOverLoseSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CPR_Model::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CPR_Model::toggleAEDSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CPR_Model::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CPR_Model::isMoveCorrect)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CPR_Model::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CPR_Model.data,
      qt_meta_data_CPR_Model,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CPR_Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CPR_Model::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CPR_Model.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CPR_Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void CPR_Model::changeStatusBoxSignal(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CPR_Model::changeTutorialBoxSignal(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CPR_Model::gameOverWinSignal(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CPR_Model::gameOverLoseSignal(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CPR_Model::toggleAEDSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CPR_Model::isMoveCorrect(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
