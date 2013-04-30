/****************************************************************************
** Meta object code from reading C++ file 'KPBBEntryHandle.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/KPBBEntryHandle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KPBBEntryHandle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KPBBEntryHandle[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
      20,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   17,   16,   16, 0x0a,
      45,   43,   16,   16, 0x0a,
      71,   65,   16,   16, 0x0a,
      93,   89,   16,   16, 0x0a,
     118,  109,   16,   16, 0x0a,
     148,  139,   16,   16, 0x0a,
     179,  171,   16,   16, 0x0a,
     210,  199,   16,   16, 0x0a,
     242,  233,   16,   16, 0x0a,
     275,  267,   16,   16, 0x0a,
     310,  299,   16,   16, 0x0a,
     344,  337,   16,   16, 0x0a,
     378,  367,   16,   16, 0x0a,

 // methods: signature, parameters, type, tag, flags
     400,   16,   16,   16, 0x02,
     426,   16,   16,   16, 0x02,
     452,   16,   16,   16, 0x02,

 // properties: name, type, flags
     476,  468, 0x00095809,
     495,  481, 0x00095809,
     509,  501, 0x03095903,
     519,  515, 0x02095903,
     539,  531, 0x0a095903,
     545,  531, 0x0a095903,
     549,  531, 0x0a095903,
     568,  558, 0x0009590b,
     577,  531, 0x0a095801,
     594,  531, 0x0a095903,
     602,  531, 0x0a095903,
     625,  613, 0x0009590b,
     634,  613, 0x0009590b,
     642,  613, 0x0009590b,
     653,  613, 0x0009590b,
     671,  660, 0x0c095903,
     678,  501, 0x03095801,
     689,  531, 0x0a095801,
     707,  702, 0x01095801,
     722,  715, 0x00095809,

       0        // eod
};

static const char qt_meta_stringdata_KPBBEntryHandle[] = {
    "KPBBEntryHandle\0\0ImageID\0setImage(quint32)\0"
    "i\0setVisualIndex(int)\0Title\0"
    "setTitle(QString)\0URL\0setUrl(QString)\0"
    "Username\0setUsername(QString)\0Password\0"
    "setPassword(SecString)\0Comment\0"
    "setComment(QString)\0BinaryDesc\0"
    "setBinaryDesc(QString)\0Creation\0"
    "setCreation(KpxDateTime)\0LastMod\0"
    "setLastMod(KpxDateTime)\0LastAccess\0"
    "setLastAccess(KpxDateTime)\0Expire\0"
    "setExpire(KpxDateTime)\0BinaryData\0"
    "setBinary(QByteArray)\0copyPasswordToClipboard()\0"
    "copyUsernameToClipboard()\0launchBrowser()\0"
    "KpxUuid\0uuid\0IGroupHandle*\0group\0"
    "quint32\0image\0int\0visualIndex\0QString\0"
    "title\0url\0username\0SecString\0password\0"
    "passwordUnlocked\0comment\0binaryDesc\0"
    "KpxDateTime\0creation\0lastMod\0lastAccess\0"
    "expire\0QByteArray\0binary\0binarySize\0"
    "friendlySize\0bool\0isValid\0CEntry\0data\0"
};

void KPBBEntryHandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KPBBEntryHandle *_t = static_cast<KPBBEntryHandle *>(_o);
        switch (_id) {
        case 0: _t->setImage((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 1: _t->setVisualIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setUsername((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setPassword((*reinterpret_cast< const SecString(*)>(_a[1]))); break;
        case 6: _t->setComment((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setBinaryDesc((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->setCreation((*reinterpret_cast< const KpxDateTime(*)>(_a[1]))); break;
        case 9: _t->setLastMod((*reinterpret_cast< const KpxDateTime(*)>(_a[1]))); break;
        case 10: _t->setLastAccess((*reinterpret_cast< const KpxDateTime(*)>(_a[1]))); break;
        case 11: _t->setExpire((*reinterpret_cast< const KpxDateTime(*)>(_a[1]))); break;
        case 12: _t->setBinary((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 13: _t->copyPasswordToClipboard(); break;
        case 14: _t->copyUsernameToClipboard(); break;
        case 15: _t->launchBrowser(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData KPBBEntryHandle::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject KPBBEntryHandle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KPBBEntryHandle,
      qt_meta_data_KPBBEntryHandle, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KPBBEntryHandle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KPBBEntryHandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KPBBEntryHandle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KPBBEntryHandle))
        return static_cast<void*>(const_cast< KPBBEntryHandle*>(this));
    if (!strcmp(_clname, "IEntryHandle"))
        return static_cast< IEntryHandle*>(const_cast< KPBBEntryHandle*>(this));
    return QObject::qt_metacast(_clname);
}

int KPBBEntryHandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 0: *reinterpret_cast< KpxUuid*>(_v) = uuid(); break;
        case 1: *reinterpret_cast< IGroupHandle**>(_v) = group(); break;
        case 2: *reinterpret_cast< quint32*>(_v) = image(); break;
        case 3: *reinterpret_cast< int*>(_v) = visualIndex(); break;
        case 4: *reinterpret_cast< QString*>(_v) = title(); break;
        case 5: *reinterpret_cast< QString*>(_v) = url(); break;
        case 6: *reinterpret_cast< QString*>(_v) = username(); break;
        case 7: *reinterpret_cast< SecString*>(_v) = password(); break;
        case 8: *reinterpret_cast< QString*>(_v) = passwordUnlocked(); break;
        case 9: *reinterpret_cast< QString*>(_v) = comment(); break;
        case 10: *reinterpret_cast< QString*>(_v) = binaryDesc(); break;
        case 11: *reinterpret_cast< KpxDateTime*>(_v) = creation(); break;
        case 12: *reinterpret_cast< KpxDateTime*>(_v) = lastMod(); break;
        case 13: *reinterpret_cast< KpxDateTime*>(_v) = lastAccess(); break;
        case 14: *reinterpret_cast< KpxDateTime*>(_v) = expire(); break;
        case 15: *reinterpret_cast< QByteArray*>(_v) = binary(); break;
        case 16: *reinterpret_cast< quint32*>(_v) = binarySize(); break;
        case 17: *reinterpret_cast< QString*>(_v) = friendlySize(); break;
        case 18: *reinterpret_cast< bool*>(_v) = isValid(); break;
        case 19: *reinterpret_cast< CEntry*>(_v) = data(); break;
        }
        _id -= 20;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: setImage(*reinterpret_cast< quint32*>(_v)); break;
        case 3: setVisualIndex(*reinterpret_cast< int*>(_v)); break;
        case 4: setTitle(*reinterpret_cast< QString*>(_v)); break;
        case 5: setUrl(*reinterpret_cast< QString*>(_v)); break;
        case 6: setUsername(*reinterpret_cast< QString*>(_v)); break;
        case 7: setPassword(*reinterpret_cast< SecString*>(_v)); break;
        case 9: setComment(*reinterpret_cast< QString*>(_v)); break;
        case 10: setBinaryDesc(*reinterpret_cast< QString*>(_v)); break;
        case 11: setCreation(*reinterpret_cast< KpxDateTime*>(_v)); break;
        case 12: setLastMod(*reinterpret_cast< KpxDateTime*>(_v)); break;
        case 13: setLastAccess(*reinterpret_cast< KpxDateTime*>(_v)); break;
        case 14: setExpire(*reinterpret_cast< KpxDateTime*>(_v)); break;
        case 15: setBinary(*reinterpret_cast< QByteArray*>(_v)); break;
        }
        _id -= 20;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 20;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
