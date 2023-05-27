#include "TrayMenuWrapper.hpp"

#include <QtGui/QIcon>

TrayMenuWrapper::TrayMenuWrapper(QObject* parent)
    : QObject(parent)
{
    menu_ = new QMenu();
}
TrayMenuWrapper::~TrayMenuWrapper()
{
    delete menu_;
}

void TrayMenuWrapper::SetTitle(const QString& title) 
{
    menu_->setTitle(title);
}
void TrayMenuWrapper::SetIcon(const QString& icon) 
{
    icon_ = icon;
    menu_->setIcon(QIcon(icon_));
}
void TrayMenuWrapper::SetMenuItemList(const QList<QObject*>& list)
{
    for (auto& el : list)
    {
        auto item = qobject_cast<TrayMenuItem*>(el);
        menu_->addAction(item->GetAction());
    }

    emit menuItemsChanged();
}

QString TrayMenuWrapper::GetTitle() const
{
    return menu_->title();
}
QString TrayMenuWrapper::GetIcon() const
{
    return icon_;
}

void TrayMenuWrapper::popup(const QPoint& point)
{
    menu_->popup(point);
}