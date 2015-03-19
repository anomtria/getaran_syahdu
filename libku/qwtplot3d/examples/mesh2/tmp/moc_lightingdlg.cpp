/****************************************************************************
** Meta object code from reading C++ file 'lightingdlg.h'
**
** Created: Tue Sep 11 10:40:19 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/lightingdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lightingdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Plot[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_Plot[] = {
    "Plot\0"
};

const QMetaObject Plot::staticMetaObject = {
    { &SPlot::staticMetaObject, qt_meta_stringdata_Plot,
      qt_meta_data_Plot, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Plot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Plot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Plot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Plot))
        return static_cast<void*>(const_cast< Plot*>(this));
    return SPlot::qt_metacast(_clname);
}

int Plot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_LightingDlg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      30,   12,   12,   12, 0x0a,
      47,   12,   12,   12, 0x0a,
      60,   12,   12,   12, 0x0a,
      73,   12,   12,   12, 0x0a,
      86,   12,   12,   12, 0x0a,
     100,   94,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LightingDlg[] = {
    "LightingDlg\0\0setDistance(int)\0"
    "setEmission(int)\0setDiff(int)\0"
    "setSpec(int)\0setShin(int)\0reset()\0"
    "x,y,z\0setRotation(double,double,double)\0"
};

const QMetaObject LightingDlg::staticMetaObject = {
    { &LightingBase::staticMetaObject, qt_meta_stringdata_LightingDlg,
      qt_meta_data_LightingDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LightingDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LightingDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LightingDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LightingDlg))
        return static_cast<void*>(const_cast< LightingDlg*>(this));
    return LightingBase::qt_metacast(_clname);
}

int LightingDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LightingBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setDistance((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setEmission((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: setDiff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: setSpec((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: setShin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: reset(); break;
        case 6: setRotation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
