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

#include "libdubomegaup/megaup.h"

#include <winsparkle.h>

#include <QtCore/qdebug.h>

namespace DuboMegaUp{

MegaUp::MegaUp(QObject * parent, const QString& aUrl, const QString& companyName, const QString& appName, const QString& version):
    QObject(parent)
{
    qDebug() << "     +++ [Lib] {MegaUp}: constructor";
    if(aUrl.length()){
        win_sparkle_set_appcast_url(aUrl.toStdString().c_str());
    }

    if(companyName.length()){
        if(companyName != ""){
            const wchar_t * cn = companyName.toStdWString().c_str();
            const wchar_t * an = appName.toStdWString().c_str();
            const wchar_t * v = version.toStdWString().c_str();
            qDebug() << "     *** [Lib] {MegaUp}: setting   infos " << (*cn) << (*an) << (*v);
            win_sparkle_set_app_details(cn, an, v);
        }
    }
    win_sparkle_init();
}

MegaUp::~MegaUp()
{
    qDebug() << "     --- [Lib] {MegaUp}: destructor";
//        Finally, you should shut WinSparkle down cleanly when the app exits:
    win_sparkle_cleanup();
}

void MegaUp::checkNow(const bool /*silent*/)
{
// Initialize WinSparkle as soon as the app itself is initialized, right
// before entering the event loop:
    qDebug() << "     *** [Lib] {MegaUp}: check for updates";
    win_sparkle_check_update_with_ui();
}

void MegaUp::setAutomatic(const bool val)
{
    qDebug() << "     *** [Lib] {MegaUp}: setting auto update" << val;
    win_sparkle_set_automatic_check_for_updates(val ? 1 : 0);
}

bool MegaUp::getAutomatic()
{
    return (win_sparkle_get_automatic_check_for_updates() == 1) ? true : false;
}

void MegaUp::setAutomaticInterval(const int seconds)
{
    qDebug() << "     *** [Lib] {MegaUp}: set interval to " << seconds;
    win_sparkle_set_update_check_interval(seconds);
}

int MegaUp::getAutomaticInterval()
{
    return win_sparkle_get_update_check_interval();
}

}
