/*
 * Copyright (c) 2019, Dubo Dubon Duponey <dubodubonduponey+github@pm.me>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DUBOUP_UP_H
#define DUBOUP_UP_H

#include "libduboup/global.h"

#include <QObject>

namespace DuboUp{

class LIBDUBOUPSHARED_EXPORT Up : public QObject
{
    Q_OBJECT
    public:
        Up(QObject * parent = nullptr, const QString& aUrl = QString(), const QString& companyName = QString(), const QString& appName = QString(), const QString& version = QString());
        ~Up();

        Q_INVOKABLE void checkNow(const bool silent = true);

        Q_PROPERTY(const bool automatic READ getAutomatic WRITE setAutomatic NOTIFY automaticChanged)
        Q_PROPERTY(const int interval READ getAutomaticInterval WRITE setAutomaticInterval NOTIFY intervalChanged)

        void setAutomatic(const bool val);
        bool getAutomatic();
        void setAutomaticInterval(const int seconds);
        int getAutomaticInterval();

    private:
        class Private;
        Private* d;

    signals:
        void automaticChanged();
        void intervalChanged();
};

}
#endif // DUBOUP_UP_H
