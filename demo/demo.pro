TEMPLATE = app
QT = core widgets webengine webenginewidgets webchannel

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

INCLUDEPATH += $$PWD
LIBS        += -l$${DUBO_LINK_NAME}
SOURCES     += $$PWD/main.cpp
RESOURCES   += $$PWD/demo.qrc

mac{
    # Add plist, and a nice icon
    OTHER_FILES         += $$PWD/Info.plist \
                           $$PWD/demo.icns

    QMAKE_INFO_PLIST    = $${PWD}/Info.plist
    ICON                = $${PWD}/demo.icns
}


mac{
    system(rm -Rf $${DESTDIR}/$${TARGET}.app/Contents/Frameworks/Sparkle.framework)
    system(mkdir -p $${DESTDIR}/$${TARGET}.app/Contents/Frameworks)
    QMAKE_PRE_LINK += $$quote(cp -rf $${DESTDIR}/../Frameworks/Sparkle.framework $${DESTDIR}/$${TARGET}.app/Contents/Frameworks)

    system(mkdir -p $${DESTDIR}/$${TARGET}.app/Contents/Resources)
    system(touch $${DESTDIR}/$${TARGET}.app/Contents/Resources/dsa_pub.pem)
    warning("Copying over template plist and bogus DSA key. For distribution, you MUST tweak the plist to fit your needs and place your proper DSA pub key inside Resources.")

    QMAKE_LFLAGS += -Wl,-rpath,@executable_path/../Frameworks

    contains(DUBO_LINK_TYPE, static){
        # Link against the embedded copy
        QMAKE_LFLAGS += -F$${DESTDIR}/$${TARGET}.app/Contents/Frameworks
    }
}


contains(DUBO_LINK_TYPE, static){
    !isEmpty(DUBO_INTERNAL){
        message( -> Using internal third-party $${DUBO_INTERNAL_VERSION})

        win32{
            copyToDestdir($$DUBO_EXTERNAL/lib/WinSparkle.dll, $$DESTDIR)
        }
    }
}

