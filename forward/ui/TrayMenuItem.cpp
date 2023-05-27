#include "TrayMenuItem.hpp"

TrayMenuItem::TrayMenuItem(QObject* parent) 
    : QObject(parent)
{
    action_ = new QAction(this);

    connect(action_, &QAction::triggered, [this](bool checked) {
        emit clicked(checked);
    });
}

TrayMenuItem::~TrayMenuItem()
{
    delete action_;
}

void TrayMenuItem::SetText(const QString& text) 
{
    action_->setText(text);
}
void TrayMenuItem::SetIcon(const QString& icon)
{
    action_->setIcon(QIcon(icon));
}

QString TrayMenuItem::GetText() const 
{
    return action_->text();
}
QIcon TrayMenuItem::GetIcon() const 
{
    return action_->icon();
}

QAction* TrayMenuItem::GetAction() const 
{
    return action_;
}