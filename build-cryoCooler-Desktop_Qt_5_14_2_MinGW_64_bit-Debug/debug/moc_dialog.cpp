/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[13];
    char stringdata0[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 19), // "on_SoftStop_pressed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 37), // "on_TargetTemperatureSpin_valu..."
QT_MOC_LITERAL(4, 66, 4), // "arg1"
QT_MOC_LITERAL(5, 71, 35), // "on_TemperatureBandSpin_valueC..."
QT_MOC_LITERAL(6, 107, 22), // "on_KISpin_valueChanged"
QT_MOC_LITERAL(7, 130, 31), // "on_PowerOutputSpin_valueChanged"
QT_MOC_LITERAL(8, 162, 22), // "on_KPSpin_valueChanged"
QT_MOC_LITERAL(9, 185, 29), // "on_RTGraphRadioButton_clicked"
QT_MOC_LITERAL(10, 215, 29), // "on_TCGraphRadioButton_clicked"
QT_MOC_LITERAL(11, 245, 44), // "on_TemperatureControlModeRadi..."
QT_MOC_LITERAL(12, 290, 38) // "on_PowerControlModeRadioButto..."

    },
    "Dialog\0on_SoftStop_pressed\0\0"
    "on_TargetTemperatureSpin_valueChanged\0"
    "arg1\0on_TemperatureBandSpin_valueChanged\0"
    "on_KISpin_valueChanged\0"
    "on_PowerOutputSpin_valueChanged\0"
    "on_KPSpin_valueChanged\0"
    "on_RTGraphRadioButton_clicked\0"
    "on_TCGraphRadioButton_clicked\0"
    "on_TemperatureControlModeRadioButton_clicked\0"
    "on_PowerControlModeRadioButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    1,   65,    2, 0x08 /* Private */,
       5,    1,   68,    2, 0x08 /* Private */,
       6,    1,   71,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       8,    1,   77,    2, 0x08 /* Private */,
       9,    0,   80,    2, 0x08 /* Private */,
      10,    0,   81,    2, 0x08 /* Private */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_SoftStop_pressed(); break;
        case 1: _t->on_TargetTemperatureSpin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_TemperatureBandSpin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_KISpin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_PowerOutputSpin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_KPSpin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_RTGraphRadioButton_clicked(); break;
        case 7: _t->on_TCGraphRadioButton_clicked(); break;
        case 8: _t->on_TemperatureControlModeRadioButton_clicked(); break;
        case 9: _t->on_PowerControlModeRadioButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog.data,
    qt_meta_data_Dialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
