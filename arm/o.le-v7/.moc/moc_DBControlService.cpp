/****************************************************************************
** Meta object code from reading C++ file 'DBControlService.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/DBControlService.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DBControlService.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DBControlService[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       2,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      40,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   58,   17,   17, 0x0a,
      74,   17,   17,   17, 0x0a,
      89,   17,   17,   17, 0x0a,
     107,   17,   17,   17, 0x0a,

 // methods: signature, parameters, type, tag, flags
     121,   17,   17,   17, 0x02,
     170,  135,   17,   17, 0x02,
     207,   17,   17,   17, 0x02,
     245,  232,   17,   17, 0x02,
     272,  270,  265,   17, 0x02,
     302,  270,  294,   17, 0x02,
     349,  325,  294,   17, 0x02,
     386,  325,  294,   17, 0x02,
     447,  425,   17,   17, 0x02,
     485,  425,   17,   17, 0x02,

 // properties: name, type, flags
     525,  294, 0x0a495103,
     531,  265, 0x01495003,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_DBControlService[] = {
    "DBControlService\0\0valueChanged(QString)\0"
    "lockChanged(bool)\0b\0setLock(bool)\0"
    "setLockTimer()\0cancelLockTimer()\0"
    "onThumbnail()\0unlockTrial()\0"
    "filePath,password,keyFile,readOnly\0"
    "unlock(QString,QString,QString,bool)\0"
    "populateGroupDataModel()\0searchString\0"
    "searchText(QString)\0bool\0u\0"
    "charcodeIsLetter(int)\0QString\0"
    "charcodeToQString(int)\0objectName,defaultValue\0"
    "getGlobalSettingFor(QString,QString)\0"
    "getDatabaseSettingFor(QString,QString)\0"
    "objectName,inputValue\0"
    "saveGlobalSettingFor(QString,QString)\0"
    "saveDatabaseSettingFor(QString,QString)\0"
    "value\0isLocked\0"
};

void DBControlService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DBControlService *_t = static_cast<DBControlService *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->lockChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setLock((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setLockTimer(); break;
        case 4: _t->cancelLockTimer(); break;
        case 5: _t->onThumbnail(); break;
        case 6: _t->unlockTrial(); break;
        case 7: _t->unlock((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 8: _t->populateGroupDataModel(); break;
        case 9: _t->searchText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: { bool _r = _t->charcodeIsLetter((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { QString _r = _t->charcodeToQString((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: { QString _r = _t->getGlobalSettingFor((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: { QString _r = _t->getDatabaseSettingFor((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: _t->saveGlobalSettingFor((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 15: _t->saveDatabaseSettingFor((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DBControlService::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DBControlService::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DBControlService,
      qt_meta_data_DBControlService, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DBControlService::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DBControlService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DBControlService::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DBControlService))
        return static_cast<void*>(const_cast< DBControlService*>(this));
    return QObject::qt_metacast(_clname);
}

int DBControlService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = value(); break;
        case 1: *reinterpret_cast< bool*>(_v) = isLocked(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setValue(*reinterpret_cast< QString*>(_v)); break;
        case 1: setLock(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
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
void DBControlService::valueChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DBControlService::lockChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
