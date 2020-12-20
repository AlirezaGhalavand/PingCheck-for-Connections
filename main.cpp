#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <QQmlContext>

#include "connection.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    connection connectionObj;
    engine.rootContext()->setContextProperty("connectionObj", &connectionObj);

    QTimer *timer = new QTimer();
    timer->setInterval(2000);
    QObject::connect(timer,&QTimer::timeout,&connectionObj,&connection::checkConnection);
    timer->start();

    return app.exec();
}
