#pragma once

#include <QtCore/QObject> 
#include <QtQml/qqmlregistration.h>

class WindowsTitleBar : QObject 
{
    Q_OBJECT
    Q_PROPERTY(std::string titleName READ GetTitleBarName WRITE SetTitleBarName NOTIFY OnTitleBarNameChanged)

private:
    std::string titlebar_name_;
    
public: 
    WindowsTitleBar();

    void SetTitleBarName(std::string name);
    std::string GetTitleBarName() const;

signals:
    void OnTitleBarNameChanged();
};
