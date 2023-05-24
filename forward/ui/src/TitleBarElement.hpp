#pragma once

#include <QtCore/QObject> 
#include <QtQml/qqmlregistration.h>

class TitleBarElement : public QObject 
{
    Q_OBJECT
    QML_NAMED_ELEMENT(TitleBar)
    Q_PROPERTY(std::string titleName READ GetTitleBarName WRITE SetTitleBarName NOTIFY OnTitleBarNameChanged)

private:
    std::string titlebar_name_;
    
public: 
    TitleBarElement();

    void SetTitleBarName(std::string name);
    std::string GetTitleBarName() const;

signals:
    void OnTitleBarNameChanged();
};
