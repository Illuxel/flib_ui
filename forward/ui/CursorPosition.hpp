#pragma once

#include <QtCore/QObject> 
#include <QtQml/QQmlEngine>
#include <QtQml/qqmlregistration.h>

#include <QtCore/QPoint>
#include <QtGui/QCursor>

class CursorPosition : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    Q_INVOKABLE static QPoint pos() { return QCursor::pos(); }
};