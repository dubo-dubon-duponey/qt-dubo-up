TEMPLATE = subdirs

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

OTHER_FILES +=  $$PWD/README.md \
                $$PWD/bootstrap.sh

# Only mac has deps for now
mac{
    !isEmpty(DUBO_INTERNAL){
        message( -> Using internal third-party $$DUBO_INTERNAL_VERSION $$DUBO_PLATFORM $$system(uname -m) $$DUBO_MIN_OSX)
        system($$PWD/bootstrap.sh $$DUBO_INTERNAL_VERSION $$DUBO_PLATFORM $$system(uname -m) $$DUBO_MIN_OSX)
    }
}
