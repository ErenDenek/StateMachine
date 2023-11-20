#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "stateboxconnlines.h"
#include "stateboxproperties.h"
#include "stateboxconnections.h"
#include "projesettings.h"

ProjeSettings projeSettings;
StateBoxProperties stateBoxProperties;
StateBoxConnection stateBoxConnection;
StateBoxConnLines stateBoxConnLines;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    engine.rootContext()->setContextProperty("stateBoxProperties", &stateBoxProperties);
    engine.rootContext()->setContextProperty("stateBoxConnection", &stateBoxConnection);
    engine.rootContext()->setContextProperty("stateBoxConnLines", &stateBoxConnLines);
    engine.rootContext()->setContextProperty("projeSettings", &projeSettings);


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
