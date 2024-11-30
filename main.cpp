// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QGuiApplication>
#include <QQmlEngine>
#include <QQuickView>

int main(int argc, char *argv[])
{
    qputenv("QT_LOGGING_RULES", QByteArray("qt.virtualkeyboard=true;qt.virtualkeyboard.debug=true"));
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    qputenv("QT_VIRTUALKEYBOARD_STYLE", QByteArray("pink"));

    QGuiApplication app(argc, argv);
    QQuickView view(QString("qrc:/%2").arg(MAIN_QML));

    if (view.status() == QQuickView::Error)
        return -1;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
