# Auto-generated by IDE. Any changes made by user will be lost!
BASEDIR =  $$quote($$_PRO_FILE_PWD_)

device {
    CONFIG(debug, debug|release) {
        SOURCES +=  $$quote($$BASEDIR/src/DBControlService.cpp) \
                 $$quote($$BASEDIR/src/Database.cpp) \
                 $$quote($$BASEDIR/src/KPBBEntryHandle.cpp) \
                 $$quote($$BASEDIR/src/KPBBGroupHandle.cpp) \
                 $$quote($$BASEDIR/src/Kdb3Database.cpp) \
                 $$quote($$BASEDIR/src/crypto/aes_modes.c) \
                 $$quote($$BASEDIR/src/crypto/aescrypt.c) \
                 $$quote($$BASEDIR/src/crypto/aeskey.c) \
                 $$quote($$BASEDIR/src/crypto/aestab.c) \
                 $$quote($$BASEDIR/src/crypto/arcfour.cpp) \
                 $$quote($$BASEDIR/src/crypto/blowfish.cpp) \
                 $$quote($$BASEDIR/src/crypto/sha256.cpp) \
                 $$quote($$BASEDIR/src/crypto/twoclass.cpp) \
                 $$quote($$BASEDIR/src/crypto/twofish.cpp) \
                 $$quote($$BASEDIR/src/crypto/yarrow.cpp) \
                 $$quote($$BASEDIR/src/lib/SecString.cpp) \
                 $$quote($$BASEDIR/src/lib/XmlReader.cpp) \
                 $$quote($$BASEDIR/src/lib/random.cpp) \
                 $$quote($$BASEDIR/src/lib/tools.cpp) \
                 $$quote($$BASEDIR/src/main.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/DBControlService.h) \
                 $$quote($$BASEDIR/src/Database.h) \
                 $$quote($$BASEDIR/src/KPBBEntryHandle.h) \
                 $$quote($$BASEDIR/src/KPBBGroupHandle.h) \
                 $$quote($$BASEDIR/src/Kdb3Database.h) \
                 $$quote($$BASEDIR/src/crypto/aes.h) \
                 $$quote($$BASEDIR/src/crypto/aes_endian.h) \
                 $$quote($$BASEDIR/src/crypto/aes_types.h) \
                 $$quote($$BASEDIR/src/crypto/aescpp.h) \
                 $$quote($$BASEDIR/src/crypto/aesopt.h) \
                 $$quote($$BASEDIR/src/crypto/aestab.h) \
                 $$quote($$BASEDIR/src/crypto/arcfour.h) \
                 $$quote($$BASEDIR/src/crypto/blowfish.h) \
                 $$quote($$BASEDIR/src/crypto/sha256.h) \
                 $$quote($$BASEDIR/src/crypto/twoclass.h) \
                 $$quote($$BASEDIR/src/crypto/twofish.h) \
                 $$quote($$BASEDIR/src/crypto/yarrow.h) \
                 $$quote($$BASEDIR/src/crypto/yarrow_macros.h) \
                 $$quote($$BASEDIR/src/keepassx.h) \
                 $$quote($$BASEDIR/src/lib/AutoType.h) \
                 $$quote($$BASEDIR/src/lib/SecString.h) \
                 $$quote($$BASEDIR/src/lib/XmlReader.h) \
                 $$quote($$BASEDIR/src/lib/random.h) \
                 $$quote($$BASEDIR/src/lib/tools.h)
    }

    CONFIG(release, debug|release) {
        SOURCES +=  $$quote($$BASEDIR/src/DBControlService.cpp) \
                 $$quote($$BASEDIR/src/Database.cpp) \
                 $$quote($$BASEDIR/src/KPBBEntryHandle.cpp) \
                 $$quote($$BASEDIR/src/KPBBGroupHandle.cpp) \
                 $$quote($$BASEDIR/src/Kdb3Database.cpp) \
                 $$quote($$BASEDIR/src/crypto/aes_modes.c) \
                 $$quote($$BASEDIR/src/crypto/aescrypt.c) \
                 $$quote($$BASEDIR/src/crypto/aeskey.c) \
                 $$quote($$BASEDIR/src/crypto/aestab.c) \
                 $$quote($$BASEDIR/src/crypto/arcfour.cpp) \
                 $$quote($$BASEDIR/src/crypto/blowfish.cpp) \
                 $$quote($$BASEDIR/src/crypto/sha256.cpp) \
                 $$quote($$BASEDIR/src/crypto/twoclass.cpp) \
                 $$quote($$BASEDIR/src/crypto/twofish.cpp) \
                 $$quote($$BASEDIR/src/crypto/yarrow.cpp) \
                 $$quote($$BASEDIR/src/lib/SecString.cpp) \
                 $$quote($$BASEDIR/src/lib/XmlReader.cpp) \
                 $$quote($$BASEDIR/src/lib/random.cpp) \
                 $$quote($$BASEDIR/src/lib/tools.cpp) \
                 $$quote($$BASEDIR/src/main.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/DBControlService.h) \
                 $$quote($$BASEDIR/src/Database.h) \
                 $$quote($$BASEDIR/src/KPBBEntryHandle.h) \
                 $$quote($$BASEDIR/src/KPBBGroupHandle.h) \
                 $$quote($$BASEDIR/src/Kdb3Database.h) \
                 $$quote($$BASEDIR/src/crypto/aes.h) \
                 $$quote($$BASEDIR/src/crypto/aes_endian.h) \
                 $$quote($$BASEDIR/src/crypto/aes_types.h) \
                 $$quote($$BASEDIR/src/crypto/aescpp.h) \
                 $$quote($$BASEDIR/src/crypto/aesopt.h) \
                 $$quote($$BASEDIR/src/crypto/aestab.h) \
                 $$quote($$BASEDIR/src/crypto/arcfour.h) \
                 $$quote($$BASEDIR/src/crypto/blowfish.h) \
                 $$quote($$BASEDIR/src/crypto/sha256.h) \
                 $$quote($$BASEDIR/src/crypto/twoclass.h) \
                 $$quote($$BASEDIR/src/crypto/twofish.h) \
                 $$quote($$BASEDIR/src/crypto/yarrow.h) \
                 $$quote($$BASEDIR/src/crypto/yarrow_macros.h) \
                 $$quote($$BASEDIR/src/keepassx.h) \
                 $$quote($$BASEDIR/src/lib/AutoType.h) \
                 $$quote($$BASEDIR/src/lib/SecString.h) \
                 $$quote($$BASEDIR/src/lib/XmlReader.h) \
                 $$quote($$BASEDIR/src/lib/random.h) \
                 $$quote($$BASEDIR/src/lib/tools.h)
    }
}

simulator {
    CONFIG(debug, debug|release) {
        SOURCES +=  $$quote($$BASEDIR/src/DBControlService.cpp) \
                 $$quote($$BASEDIR/src/Database.cpp) \
                 $$quote($$BASEDIR/src/KPBBEntryHandle.cpp) \
                 $$quote($$BASEDIR/src/KPBBGroupHandle.cpp) \
                 $$quote($$BASEDIR/src/Kdb3Database.cpp) \
                 $$quote($$BASEDIR/src/crypto/aes_modes.c) \
                 $$quote($$BASEDIR/src/crypto/aescrypt.c) \
                 $$quote($$BASEDIR/src/crypto/aeskey.c) \
                 $$quote($$BASEDIR/src/crypto/aestab.c) \
                 $$quote($$BASEDIR/src/crypto/arcfour.cpp) \
                 $$quote($$BASEDIR/src/crypto/blowfish.cpp) \
                 $$quote($$BASEDIR/src/crypto/sha256.cpp) \
                 $$quote($$BASEDIR/src/crypto/twoclass.cpp) \
                 $$quote($$BASEDIR/src/crypto/twofish.cpp) \
                 $$quote($$BASEDIR/src/crypto/yarrow.cpp) \
                 $$quote($$BASEDIR/src/lib/SecString.cpp) \
                 $$quote($$BASEDIR/src/lib/XmlReader.cpp) \
                 $$quote($$BASEDIR/src/lib/random.cpp) \
                 $$quote($$BASEDIR/src/lib/tools.cpp) \
                 $$quote($$BASEDIR/src/main.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/DBControlService.h) \
                 $$quote($$BASEDIR/src/Database.h) \
                 $$quote($$BASEDIR/src/KPBBEntryHandle.h) \
                 $$quote($$BASEDIR/src/KPBBGroupHandle.h) \
                 $$quote($$BASEDIR/src/Kdb3Database.h) \
                 $$quote($$BASEDIR/src/crypto/aes.h) \
                 $$quote($$BASEDIR/src/crypto/aes_endian.h) \
                 $$quote($$BASEDIR/src/crypto/aes_types.h) \
                 $$quote($$BASEDIR/src/crypto/aescpp.h) \
                 $$quote($$BASEDIR/src/crypto/aesopt.h) \
                 $$quote($$BASEDIR/src/crypto/aestab.h) \
                 $$quote($$BASEDIR/src/crypto/arcfour.h) \
                 $$quote($$BASEDIR/src/crypto/blowfish.h) \
                 $$quote($$BASEDIR/src/crypto/sha256.h) \
                 $$quote($$BASEDIR/src/crypto/twoclass.h) \
                 $$quote($$BASEDIR/src/crypto/twofish.h) \
                 $$quote($$BASEDIR/src/crypto/yarrow.h) \
                 $$quote($$BASEDIR/src/crypto/yarrow_macros.h) \
                 $$quote($$BASEDIR/src/keepassx.h) \
                 $$quote($$BASEDIR/src/lib/AutoType.h) \
                 $$quote($$BASEDIR/src/lib/SecString.h) \
                 $$quote($$BASEDIR/src/lib/XmlReader.h) \
                 $$quote($$BASEDIR/src/lib/random.h) \
                 $$quote($$BASEDIR/src/lib/tools.h)
    }
}

INCLUDEPATH +=  $$quote($$BASEDIR/src/lib) \
         $$quote($$BASEDIR/src) \
         $$quote($$BASEDIR/src/crypto)

CONFIG += precompile_header

PRECOMPILED_HEADER =  $$quote($$BASEDIR/precompiled.h)

lupdate_inclusion {
    SOURCES +=  $$quote($$BASEDIR/../src/*.c) \
             $$quote($$BASEDIR/../src/*.c++) \
             $$quote($$BASEDIR/../src/*.cc) \
             $$quote($$BASEDIR/../src/*.cpp) \
             $$quote($$BASEDIR/../src/*.cxx) \
             $$quote($$BASEDIR/../assets/*.qml) \
             $$quote($$BASEDIR/../assets/*.js) \
             $$quote($$BASEDIR/../assets/*.qs)

    HEADERS +=  $$quote($$BASEDIR/../src/*.h) \
             $$quote($$BASEDIR/../src/*.h++) \
             $$quote($$BASEDIR/../src/*.hh) \
             $$quote($$BASEDIR/../src/*.hpp) \
             $$quote($$BASEDIR/../src/*.hxx)
}

TRANSLATIONS =  $$quote($${TARGET}.ts)
