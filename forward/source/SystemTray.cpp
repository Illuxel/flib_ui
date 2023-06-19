#include "SystemTray.hpp"

#include <QtGui/QIcon>

SystemTray::SystemTray(QObject* parent)
    : QObject(parent) 
{
    sys_tray_ = new QSystemTrayIcon(this);

    connect(sys_tray_, &QSystemTrayIcon::activated, [this](QSystemTrayIcon::ActivationReason reason) {  
        
        switch (reason)
        {
        case QSystemTrayIcon::Unknown: emit trayUnknown();
            break;
        case QSystemTrayIcon::Context: emit trayContext();
            break;
        case QSystemTrayIcon::DoubleClick: emit trayDoubleClicked();
            break;
        case QSystemTrayIcon::Trigger: emit trayTriggered();
            break;
        case QSystemTrayIcon::MiddleClick: emit trayMiddleClicked();
            break;
        }
    });
    connect(sys_tray_, &QSystemTrayIcon::messageClicked, [this]() {
        emit messageClicked();
    });
}
SystemTray::~SystemTray() 
{
    delete sys_tray_;
}

void SystemTray::SetTrayIconSource(const QString& source) 
{
    tray_icon_source_ = source;
    sys_tray_->setIcon(QIcon(source));
    sys_tray_->setVisible(true);
}
void SystemTray::SetMessageIconSource(const QString& source) 
{
    msg_icon_source_ = source;
}
void SystemTray::SetMenu(TrayMenuWrapper* menu) 
{
    menu_wrapper_ = menu;
}

void SystemTray::SetVisible(bool visible) 
{
    sys_tray_->setVisible(visible);
}

QString SystemTray::GetTrayIconSource() const
{
    return tray_icon_source_;
}
QString SystemTray::GetMessageIconSource() const
{
    return msg_icon_source_;
}
TrayMenuWrapper* SystemTray::GetMenu() const
{
    return menu_wrapper_;
}

bool SystemTray::IsVisible() const 
{
    return sys_tray_->isVisible();
}

void SystemTray::showTrayIcon()
{
    sys_tray_->show();
}
void SystemTray::hideTrayIcon()
{
    sys_tray_->hide();
}

void SystemTray::showMessage(const QString& title, const QString& msg, int millisecondsTimeoutHint) 
{
    sys_tray_->showMessage(title, msg, QIcon(msg_icon_source_), millisecondsTimeoutHint);
}
void SystemTray::showMessage(const QString& title, const QString& msg, const QIcon& ico, int millisecondsTimeoutHint)
{
    sys_tray_->showMessage(title, msg, ico, millisecondsTimeoutHint);
}