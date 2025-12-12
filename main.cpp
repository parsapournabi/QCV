#include <QGuiApplication>

#include "QmlEngine.h"

int main(int argc, char* argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QEngine engine;
    QString curFile = "file:///" + QString(__FILE__);
    QString mainQmlPath = curFile.replace("main.cpp", "main.qml").replace("\\", "/");

    const QUrl url(mainQmlPath);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject * obj, const QUrl & objUrl)
    {
        if (!obj && url == objUrl)
        {
            QCoreApplication::exit(-1);
        }
    },
    Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("$Engine", &engine);
    engine.load(url);

    return app.exec();
}
