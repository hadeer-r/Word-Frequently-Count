#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<iostream>
#include"Words.hpp"
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Word_Frequently_Count/qml/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
