#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <QQuickView>
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
//    QQuickView view;
//    view.setSource(QUrl::fromLocalFile("main.qml"));


    connection connectionObj;
//    view.rootContext()->setContextProperty("connectionObject", &connectionObj);
//    QQmlContext* context = engine.rootContext();
//    context->setContextProperty("connectionObj", &connectionObj);
    engine.rootContext()->setContextProperty("connectionObj", &connectionObj); //even simpler

    QTimer *timer = new QTimer();
    timer->setInterval(2000);
    QObject::connect(timer,&QTimer::timeout,&connectionObj,&connection::checkConnection);
    timer->start();

//    view.show();

    return app.exec();
}
