/****************************************************************************
** Meta object code from reading C++ file 'enrichmentmainwindow.h'
**
** Created: Tue Sep 11 10:40:24 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/enrichmentmainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enrichmentmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EnrichmentMainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x0a,
      36,   21,   21,   21, 0x0a,
      50,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EnrichmentMainWindow[] = {
    "EnrichmentMainWindow\0\0setLevel(int)\0"
    "setWidth(int)\0barSlot()\0"
};

const QMetaObject EnrichmentMainWindow::staticMetaObject = {
    { &DummyBase::staticMetaObject, qt_meta_stringdata_EnrichmentMainWindow,
      qt_meta_data_EnrichmentMainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EnrichmentMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EnrichmentMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EnrichmentMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EnrichmentMainWindow))
        return static_cast<void*>(const_cast< EnrichmentMainWindow*>(this));
    return DummyBase::qt_metacast(_clname);
}

int EnrichmentMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DummyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: barSlot(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
