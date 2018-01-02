TEMPLATE = app
QT = core widgets

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

INCLUDEPATH += $$PWD

LIBS += -l$${DUBO_LINK_NAME}

SOURCES +=  $$PWD/main.cpp

mac{
    system(rm -Rf $${DESTDIR}/$${TARGET}.app/Contents/Frameworks/Sparkle.framework)
    system(mkdir -p $${DESTDIR}/$${TARGET}.app/Contents/Frameworks)
    system(cp -R $${DESTDIR}/../Frameworks/Sparkle.framework $${DESTDIR}/$${TARGET}.app/Contents/Frameworks)
    system(mkdir -p $${DESTDIR}/$${TARGET}.app/Contents/Resources)
    system(touch $${DESTDIR}/$${TARGET}.app/Contents/Resources/dsa_pub.pem)
    warning("Copying over template plist and bogus DSA key. For distribution, you MUST tweak the plist to fit your needs and place your proper DSA pub key inside Resources.")
    # XXX force rpath here to make it work (for 5.7), and make it work from ../Frameworks for 5.10
    QMAKE_LFLAGS += -Wl,-rpath,@executable_path/../Frameworks

    # Add plist with Sparkle properties
    OTHER_FILES += $$PWD/Info.plist
    QMAKE_INFO_PLIST = $${PWD}/Info.plist
}

contains(DUBO_LINK_TYPE, static){
    DEFINES += LIBDUBOMEGAUP_USE_STATIC

    mac{
        # Link against the embedded copy
        QMAKE_LFLAGS += -F$${DESTDIR}/$${TARGET}.app/Contents/Frameworks
    }

    !isEmpty(DUBO_INTERNAL){
        message( -> Using internal third-party $${DUBO_INTERNAL_VERSION})
        win32{
            copyToDestdir($$DUBO_EXTERNAL/lib/WinSparkle.dll, $$DESTDIR)
        }
    }
}

