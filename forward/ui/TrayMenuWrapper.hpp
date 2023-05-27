#pragma once

#include "TrayMenuItem.hpp"

#include <QtWidgets/QMenu>
#include <QQmlListProperty>

class TrayMenuWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ GetTitle WRITE SetTitle)
    Q_PROPERTY(QString icon READ GetIcon WRITE SetIcon)
    Q_PROPERTY(QList<QObject*> menuItems WRITE SetMenuItemList NOTIFY menuItemsChanged)
    QML_ELEMENT

private:
    QString icon_;
    QMenu* menu_;

public:
    explicit TrayMenuWrapper(QObject* parent = nullptr);
    ~TrayMenuWrapper() override;

    void SetTitle(const QString& title);
    void SetIcon(const QString& icon);
    void SetMenuItemList(const QList<QObject*>& list);

    QString GetTitle() const;
    QString GetIcon() const;

    Q_INVOKABLE void popup(const QPoint& point);

signals:
    void menuItemsChanged();

};