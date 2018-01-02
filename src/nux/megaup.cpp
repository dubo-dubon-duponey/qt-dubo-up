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

#include <QtCore/qdebug.h>

namespace DuboMegaUp{

MegaUp::MegaUp(QObject * parent, const QString& /*aUrl*/, const QString& /*companyName*/, const QString& /*appName*/, const QString& /*version*/):
    QObject(parent)
{
    qDebug() << "     +++ [Lib] {MegaUp}: constructor";
}

MegaUp::~MegaUp()
{
    qDebug() << "     --- [Lib] {MegaUp}: destructor";
}

void MegaUp::checkNow(const bool /*silent*/)
{
    qDebug() << "     *** [Lib] {MegaUp}: check for updates";
}

void MegaUp::setAutomatic(const bool /*val*/)
{
}

bool MegaUp::getAutomatic()
{
    return 0;
}

void MegaUp::setAutomaticInterval(const int /*seconds*/)
{
}

int MegaUp::getAutomaticInterval()
{
    return 0;
}

}
