/****************************************************************************
** Meta object code from reading C++ file 'gamewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CPRGame/gamewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameWindow_t {
    QByteArrayData data[23];
    char stringdata0[415];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameWindow_t qt_meta_stringdata_GameWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameWindow"
QT_MOC_LITERAL(1, 11, 6), // "action"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "state"
QT_MOC_LITERAL(4, 25, 21), // "on_callAction_clicked"
QT_MOC_LITERAL(5, 47, 20), // "on_cprAction_clicked"
QT_MOC_LITERAL(6, 68, 23), // "on_breathAction_clicked"
QT_MOC_LITERAL(7, 92, 30), // "on_checkResponseAction_clicked"
QT_MOC_LITERAL(8, 123, 28), // "on_checkBreathAction_clicked"
QT_MOC_LITERAL(9, 152, 12), // "SetStatusBox"
QT_MOC_LITERAL(10, 165, 6), // "string"
QT_MOC_LITERAL(11, 172, 1), // "s"
QT_MOC_LITERAL(12, 174, 14), // "SetTutorialBox"
QT_MOC_LITERAL(13, 189, 13), // "toggleAEDSlot"
QT_MOC_LITERAL(14, 203, 6), // "toggle"
QT_MOC_LITERAL(15, 210, 25), // "on_AEDPowerButton_clicked"
QT_MOC_LITERAL(16, 236, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(17, 260, 21), // "on_shoutClear_clicked"
QT_MOC_LITERAL(18, 282, 21), // "on_padsButton_clicked"
QT_MOC_LITERAL(19, 304, 27), // "on_playAgainButton_released"
QT_MOC_LITERAL(20, 332, 26), // "on_tryAgainButton_released"
QT_MOC_LITERAL(21, 359, 36), // "on_checkBreathAndPulseButton_..."
QT_MOC_LITERAL(22, 396, 18) // "setCursorToDefault"

    },
    "GameWindow\0action\0\0state\0on_callAction_clicked\0"
    "on_cprAction_clicked\0on_breathAction_clicked\0"
    "on_checkResponseAction_clicked\0"
    "on_checkBreathAction_clicked\0SetStatusBox\0"
    "string\0s\0SetTutorialBox\0toggleAEDSlot\0"
    "toggle\0on_AEDPowerButton_clicked\0"
    "on_pushButton_6_clicked\0on_shoutClear_clicked\0"
    "on_padsButton_clicked\0on_playAgainButton_released\0"
    "on_tryAgainButton_released\0"
    "on_checkBreathAndPulseButton_clicked\0"
    "setCursorToDefault"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  102,    2, 0x08 /* Private */,
       5,    0,  103,    2, 0x08 /* Private */,
       6,    0,  104,    2, 0x08 /* Private */,
       7,    0,  105,    2, 0x08 /* Private */,
       8,    0,  106,    2, 0x08 /* Private */,
       9,    1,  107,    2, 0x08 /* Private */,
      12,    1,  110,    2, 0x08 /* Private */,
      13,    1,  113,    2, 0x08 /* Private */,
      15,    0,  116,    2, 0x08 /* Private */,
      16,    0,  117,    2, 0x08 /* Private */,
      17,    0,  118,    2, 0x08 /* Private */,
      18,    0,  119,    2, 0x08 /* Private */,
      19,    0,  120,    2, 0x08 /* Private */,
      20,    0,  121,    2, 0x08 /* Private */,
      21,    0,  122,    2, 0x08 /* Private */,
      22,    0,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameWindow *_t = static_cast<GameWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->action((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_callAction_clicked(); break;
        case 2: _t->on_cprAction_clicked(); break;
        case 3: _t->on_breathAction_clicked(); break;
        case 4: _t->on_checkResponseAction_clicked(); break;
        case 5: _t->on_checkBreathAction_clicked(); break;
        case 6: _t->SetStatusBox((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 7: _t->SetTutorialBox((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 8: _t->toggleAEDSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_AEDPowerButton_clicked(); break;
        case 10: _t->on_pushButton_6_clicked(); break;
        case 11: _t->on_shoutClear_clicked(); break;
        case 12: _t->on_padsButton_clicked(); break;
        case 13: _t->on_playAgainButton_released(); break;
        case 14: _t->on_tryAgainButton_released(); break;
        case 15: _t->on_checkBreathAndPulseButton_clicked(); break;
        case 16: _t->setCursorToDefault(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GameWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameWindow::action)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject GameWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GameWindow.data,
      qt_meta_data_GameWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GameWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void GameWindow::action(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
