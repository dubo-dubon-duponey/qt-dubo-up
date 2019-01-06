/**
 * Copyright (c) 2019, Dubo Dubon Duponey <dubodubonduponey+github@pm.me>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <QDebug>
#include <QApplication>
#include <libduboup/up.h>
#include <libduboup/root.h>
#include <QWidget>

#include <QtWebEngine>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QFileInfo>
#include <QDir>
#include <QWebChannel>

QWebChannel * SetupWebView()
{
    QFileInfo jsFileInfo(QDir::currentPath() + "/qwebchannel.js");

    if (!jsFileInfo.exists())
        QFile::copy(":/qtwebchannel/qwebchannel.js", jsFileInfo.absoluteFilePath());

    QtWebEngine::initialize();
    QWebEngineView * view = new QWebEngineView();

    QWebChannel * channel = new QWebChannel(view->page());
    view->page()->setWebChannel(channel);

    view->load(QUrl("qrc:/demo.html"));
    view->show();

    return channel;
}

void OutputLibraryInfo(){
    DuboUp::Root * root = new DuboUp::Root();
    qDebug() << root->property("NAME");
    qDebug() << root->property("VENDOR");
    qDebug() << root->property("VERSION");
    qDebug() << root->property("REVISION");
    qDebug() << root->property("CHANGESET");
    qDebug() << root->property("BUILD");
    qDebug() << root->property("LINK");
    qDebug() << root->property("QT");
    qDebug() << root->property("PLUGIN_NAME");
    qDebug() << root->property("PLUGIN_VERSION");
    qDebug() << root->property("PLUGIN_REVISION");
}

int main(int argc, char *argv[])
{
    // Get your app going
    QApplication app(argc, argv);

    // Display the webview
    QWebChannel * chan = SetupWebView();

    QObject * r = new QObject;
    QString u = QString::fromLatin1("https://qtduboup/appcast.xml");
    // Instanciate our main objects
    DuboUp::Root * root = new DuboUp::Root();
    DuboUp::Up * updater = new DuboUp::Up(r, u, root->getVendor(), root->getName(), root->getVersion());
    // Attach objects to the javascript context
    chan->registerObject("Root", root);
    chan->registerObject("Dubo", updater);

    updater->setAutomatic(true);
    updater->setAutomaticInterval(3600 * 24);
    // Check updates
    updater->checkNow();

    return app.exec();
}
