#ifndef QMLENGINE_H
#define QMLENGINE_H

#include <QQmlApplicationEngine>
#include <QQmlContext>

class QEngine : public QQmlApplicationEngine
{
        Q_OBJECT

    public:

        using QQmlApplicationEngine::QQmlApplicationEngine;

        Q_INVOKABLE void clearCache()
        {
            clearComponentCache();
        }
};

#endif // QMLENGINE_H
