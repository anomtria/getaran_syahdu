/****************************************************************************
** Meta object code from reading C++ file 'mesh2mainwindow.h'
**
** Created: Tue Sep 11 10:40:18 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mesh2mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mesh2mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Mesh2MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      24,   16,   16,   16, 0x0a,
      40,   35,   16,   16, 0x0a,
      64,   35,   16,   16, 0x0a,
      88,   35,   16,   16, 0x0a,
     109,   16,   16,   16, 0x0a,
     135,   16,   16,   16, 0x0a,
     159,   16,   16,   16, 0x0a,
     184,   16,   16,   16, 0x0a,
     200,   16,   16,   16, 0x0a,
     214,   16,   16,   16, 0x0a,
     230,   16,   16,   16, 0x0a,
     248,   16,   16,   16, 0x0a,
     265,   16,   16,   16, 0x0a,
     282,   16,   16,   16, 0x0a,
     298,   16,   16,   16, 0x0a,
     313,   16,   16,   16, 0x0a,
     327,   16,   16,   16, 0x0a,
     344,   16,   16,   16, 0x0a,
     360,   16,   16,   16, 0x0a,
     376,   16,   16,   16, 0x0a,
     389,   16,   16,   16, 0x0a,
     407,   16,   16,   16, 0x0a,
     419,   16,   16,   16, 0x0a,
     441,   16,   16,   16, 0x0a,
     468,   16,   16,   16, 0x0a,
     496,  492,   16,   16, 0x0a,
     518,  492,   16,   16, 0x0a,
     537,   16,   16,   16, 0x0a,
     546,   16,   16,   16, 0x0a,
     574,  568,   16,   16, 0x0a,
     611,  607,   16,   16, 0x0a,
     636,  568,   16,   16, 0x0a,
     670,  668,   16,   16, 0x0a,
     687,  492,   16,   16, 0x0a,
     705,   16,   16,   16, 0x0a,
     727,   16,   16,   16, 0x0a,
     762,  753,  748,   16, 0x0a,
     804,   16,   16,   16, 0x0a,
     843,  829,   16,   16, 0x0a,
     872,  870,   16,   16, 0x0a,
     890,  870,   16,   16, 0x0a,
     909,  870,   16,   16, 0x0a,
     927,  870,   16,   16, 0x0a,
     946,  870,   16,   16, 0x0a,
     965,  870,   16,   16, 0x0a,
     985,  983,   16,   16, 0x0a,
    1011,  492,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Mesh2MainWindow[] = {
    "Mesh2MainWindow\0\0open()\0openMesh()\0"
    "name\0createFunction(QString)\0"
    "createPSurface(QString)\0setFileType(QString)\0"
    "pickCoordSystem(QAction*)\0"
    "pickPlotStyle(QAction*)\0"
    "pickFloorStyle(QAction*)\0pickAxesColor()\0"
    "pickBgColor()\0pickMeshColor()\0"
    "pickNumberColor()\0pickLabelColor()\0"
    "pickTitleColor()\0pickDataColor()\0"
    "pickLighting()\0resetColors()\0"
    "pickNumberFont()\0pickLabelFont()\0"
    "pickTitleFont()\0resetFonts()\0"
    "setStandardView()\0dumpImage()\0"
    "toggleAnimation(bool)\0toggleProjectionMode(bool)\0"
    "toggleColorLegend(bool)\0val\0"
    "toggleAutoScale(bool)\0toggleShader(bool)\0"
    "rotate()\0setPolygonOffset(int)\0x,y,z\0"
    "showRotate(double,double,double)\0x,y\0"
    "showShift(double,double)\0"
    "showScale(double,double,double)\0z\0"
    "showZoom(double)\0showNormals(bool)\0"
    "setNormalQuality(int)\0setNormalLength(int)\0"
    "bool\0cv,fname\0openColorMap(Qwt3D::ColorVector&,QString)\0"
    "adaptDataColors(QString)\0majors,minors\0"
    "updateColorLegend(int,int)\0b\0"
    "setLeftGrid(bool)\0setRightGrid(bool)\0"
    "setCeilGrid(bool)\0setFloorGrid(bool)\0"
    "setFrontGrid(bool)\0setBackGrid(bool)\0"
    ",\0setGrid(Qwt3D::SIDE,bool)\0"
    "enableLighting(bool)\0"
};

const QMetaObject Mesh2MainWindow::staticMetaObject = {
    { &DummyBase::staticMetaObject, qt_meta_stringdata_Mesh2MainWindow,
      qt_meta_data_Mesh2MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Mesh2MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Mesh2MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Mesh2MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Mesh2MainWindow))
        return static_cast<void*>(const_cast< Mesh2MainWindow*>(this));
    return DummyBase::qt_metacast(_clname);
}

int Mesh2MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DummyBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: open(); break;
        case 1: openMesh(); break;
        case 2: createFunction((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: createPSurface((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: setFileType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: pickCoordSystem((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 6: pickPlotStyle((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: pickFloorStyle((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 8: pickAxesColor(); break;
        case 9: pickBgColor(); break;
        case 10: pickMeshColor(); break;
        case 11: pickNumberColor(); break;
        case 12: pickLabelColor(); break;
        case 13: pickTitleColor(); break;
        case 14: pickDataColor(); break;
        case 15: pickLighting(); break;
        case 16: resetColors(); break;
        case 17: pickNumberFont(); break;
        case 18: pickLabelFont(); break;
        case 19: pickTitleFont(); break;
        case 20: resetFonts(); break;
        case 21: setStandardView(); break;
        case 22: dumpImage(); break;
        case 23: toggleAnimation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: toggleProjectionMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: toggleColorLegend((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: toggleAutoScale((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: toggleShader((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: rotate(); break;
        case 29: setPolygonOffset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: showRotate((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 31: showShift((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 32: showScale((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 33: showZoom((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 34: showNormals((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: setNormalQuality((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: setNormalLength((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: { bool _r = openColorMap((*reinterpret_cast< Qwt3D::ColorVector(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 38: adaptDataColors((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 39: updateColorLegend((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 40: setLeftGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: setRightGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: setCeilGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: setFloorGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: setFrontGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: setBackGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: setGrid((*reinterpret_cast< Qwt3D::SIDE(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 47: enableLighting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 48;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
