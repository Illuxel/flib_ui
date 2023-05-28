#pragma once

#include "TrayMenuWrapper.hpp"

#include <QtWidgets/QSystemTrayIcon>

class SystemTray : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool visible READ IsVisible WRITE SetVisible) 
    Q_PROPERTY(QString iconTray MEMBER tray_icon_source_ WRITE SetTrayIconSource)
    Q_PROPERTY(QString iconMsg MEMBER msg_icon_source_ WRITE SetMessageIconSource)
    Q_PROPERTY(TrayMenuWrapper* menu READ GetMenu WRITE SetMenu)
    QML_ELEMENT

private: 
    QString tray_icon_source_, msg_icon_source_;
    QSystemTrayIcon* sys_tray_;
    TrayMenuWrapper* menu_wrapper_;

public: 
    explicit SystemTray(QObject* parent = nullptr);
    ~SystemTray() override;

    void SetTrayIconSource(const QString& source);
    void SetMessageIconSource(const QString& source);
    void SetMenu(TrayMenuWrapper* menu);

    void SetVisible(bool visible);

    QString GetTrayIconSource() const;
    QString GetMessageIconSource() const;
    TrayMenuWrapper* GetMenu() const;

    bool IsVisible() const;

    Q_INVOKABLE void showTrayIcon();
    Q_INVOKABLE void hideTrayIcon();

    Q_INVOKABLE void showMessage(const QString& title, const QString& msg, int millisecondsTimeoutHint = 10000);

signals: 
    void trayContext();
    void trayTriggered();
    void trayDoubleClicked();
    void trayMiddleClicked();
    void trayUnknown();

    void messageClicked();
};