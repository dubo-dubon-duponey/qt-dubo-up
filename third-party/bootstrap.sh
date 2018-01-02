#!/bin/sh

TP_VERSION=$1

download(){
    local version=$1
    if [ ! -f $version.tar.gz ]; then
        echo "Downloading Sparkle $version"
        curl https://codeload.github.com/sparkle-project/Sparkle/tar.gz/$version > $version.tar.gz
        if [[ $? != 0 ]]; then
            echo "cleanup"
            rm $version.tar.gz
        fi
    fi
    if [ ! -d $version ]; then
        echo "Extracting Sparkle $version"
        mkdir $version
        tar -xzf $version.tar.gz -C $version
        if [[ $? != 0 ]]; then
            echo "cleanup"
            rm -Rf $version
        fi
    fi
}

build(){
    local source=$1/Sparkle-$1
    local dest=$1.build
    if [ ! -d $dest ]; then
        cd "$source"
        xcodebuild -project Sparkle.xcodeproj -sdk macosx$(xcrun --show-sdk-version) MACOSX_DEPLOYMENT_TARGET=10.7 -target Sparkle -configuration Release GCC_TREAT_WARNINGS_AS_ERRORS=NO ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES
        #
        if [[ $? != 0 ]]; then
            echo "Failed to build!"
            exit 1
        fi
        cd -
        mkdir $dest
        mv "$source/build/Release" "$dest/Frameworks"
    fi
}

download $TP_VERSION
build $TP_VERSION


exit

# FAILS on master for some reaso... GCC_VERSION=com.apple.compilers.llvmgcc42
#    cp ${SRC_DIR}/generate_keys.rb ${BUILD_DIR}/../
#    cp ${SRC_DIR}/sign_update.rb ${BUILD_DIR}/../
#    chmod u+x ${BUILD_DIR}/../sign_update.rb
#    chmod u+x ${BUILD_DIR}/../generate_keys.rb

fixbuild(){
# Fix broken includes
    cd ${BUILD_DIR}/Sparkle.framework/Headers/
    ln -s ../Headers Sparkle
    cd -

# Fix resources symlinks
    cd ${BUILD_DIR}/Sparkle.framework/Resources
    rm fr_CA.lproj
#    rm fr.lproj/fr.lproj
    ln -s fr.lproj fr_CA.lproj
    cd -
}

relink(){
    rm -f sparkler-mac/Frameworks
    mkdir -p sparkler-mac
    ln -s `pwd`/${BUILD_DIR} sparkler-mac/Frameworks
}
