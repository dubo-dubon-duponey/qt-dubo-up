TEMPLATE = lib
QT = core

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

INCLUDEPATH += $$PWD

HEADERS +=  $$PWD/lib$${TARGET}/global.h \
            $$PWD/lib$${TARGET}/root.h \
            $$PWD/lib$${TARGET}/up.h

SOURCES +=  $$PWD/root.cpp

mac {
    HEADERS +=              $$PWD/mac/cocoainit.h
    OBJECTIVE_SOURCES +=    $$PWD/mac/cocoainit.mm \
                            $$PWD/mac/up.mm
}

win32 {
    SOURCES += $$PWD/win/up.cpp
}

!mac:!win32{
    SOURCES += $$PWD/nux/up.cpp
}

# Copy over the framework to the build destination so that apps can embed the framework from a consistent place
mac{
    system(rm -Rf $${DESTDIR}/../Frameworks/Sparkle.framework)
    system(mkdir -p $${DESTDIR}/../Frameworks)
    # XXX PRE does not get called on libraries? XXXXXX
    # This is still wonky
    QMAKE_POST_LINK += $$quote(cp -rf $${DUBO_EXTERNAL}/Frameworks/Sparkle.framework $${DESTDIR}/../Frameworks/)
}

contains(DUBO_LINK_TYPE, dynamic){
    message( -> Using internal third-party $${DUBO_INTERNAL_VERSION})
    win32{
        copyToDestdir($${DUBO_EXTERNAL}/lib/WinSparkle.dll, $$DESTDIR)
    }
}
