TEMPLATE = lib
QT = core

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

INCLUDEPATH += $$PWD

DEFINES += LIBDUBOMEGAUP_LIBRARY
contains(DUBO_LINK_TYPE, static){
    DEFINES += LIBDUBOMEGAUP_USE_STATIC
}

copyToDestdir($$PWD/lib$${TARGET}/*, $$DESTDIR/../include/lib$${TARGET})
copyToDestdir($$PWD/../res/redist/*, $$DESTDIR/../share/lib$${TARGET})

#!isEmpty(DUBO_INTERNAL){
contains(DUBO_LINK_TYPE, dynamic){
    message( -> Using internal third-party $${DUBO_INTERNAL_VERSION})
    win32{
        copyToDestdir($${DUBO_EXTERNAL}/lib/WinSparkle.dll, $$DESTDIR)
    }
}

# Copy over the framework to the build destination so that apps can embed the framework from a consistent place
mac{
    system(rm -Rf $${DESTDIR}/../Frameworks/Sparkle.framework)
    system(mkdir -p $${DESTDIR}/../Frameworks)
    system(cp -R $${DUBO_EXTERNAL}/Frameworks/Sparkle.framework $${DESTDIR}/../Frameworks)
}

SOURCES +=  $$PWD/root.cpp

HEADERS +=  $$PWD/lib$${TARGET}/lib$${TARGET}_global.h \
            $$PWD/lib$${TARGET}/root.h \
            $$PWD/lib$${TARGET}/megaup.h

mac {
    HEADERS +=              $$PWD/mac/cocoainit.h
    OBJECTIVE_SOURCES +=    $$PWD/mac/cocoainit.mm
    OBJECTIVE_SOURCES +=    $$PWD/mac/megaup.mm
}

win32 {
    SOURCES += $$PWD/win/megaup.cpp
}

!mac:!win32{
    SOURCES += $$PWD/nux/megaup.cpp
}
