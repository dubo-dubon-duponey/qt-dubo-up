/**
 * Copyright (c) 2018, Dubo Dubon Duponey <dubodubonduponey@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "libdubomegaup/root.h"

#if defined(Q_OS_WIN)
#include "winsparkle-version.h"
#endif

/*! \cond */

namespace DuboMegaUp{

const QString Root::getName(){
    return PROJECT_NAME;
}

const QString Root::getVendor(){
    return PROJECT_VENDOR;
}

const QString Root::getVersion(){
    return VERSION_FULL;
}

const QString Root::getRevision(){
    return VERSION_GIT;
}

const QString Root::getChangeset(){
    return VERSION_CHANGE;
}

const QString Root::getBuildType(){
    return PROJECT_BUILDTYPE;
}

const QString Root::getLinkType(){
    return PROJECT_LINKTYPE;
}

//const QString Root::getHost(){
//    return PROJECT_HOST;
//}

//const QString Root::getCompiler(){
//    return PROJECT_COMPILER;
//}

const QString Root::getQt(){
    return QT_VERSION_STR;
}

const QString Root::getLibName(){
#if defined(Q_OS_MAC)
    return QString::fromLatin1("sparkle");
#elif defined(Q_OS_WIN)
    return QString::fromLatin1("winsparkle");
#else
    return QString::fromLatin1("");
#endif
}

const QString Root::getLibVersion(){
#if defined(Q_OS_MAC)
    // XXX should better read the info.plist
    return QString::fromLatin1("1");
#elif defined(Q_OS_WIN)
    return QString::number(WIN_SPARKLE_VERSION_MAJOR);
#else
    return QString::fromLatin1("");
#endif
}

const QString Root::getLibRevision(){
#if defined(Q_OS_MAC)
    // XXX should better read the info.plist
    return QString::fromLatin1("5b6");
#elif defined(Q_OS_WIN)
    return QString::number(WIN_SPARKLE_VERSION_MINOR);
#else
    return QString::fromLatin1("");
#endif
}

}

/*! \endcond */
