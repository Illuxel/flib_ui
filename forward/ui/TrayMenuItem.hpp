#pragma once

#include <QtCore/QObject>
#include <QtQml/qqmlregistration.h>

#include <QtGui/QAction>

class TrayMenuItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ GetText WRITE SetText)
    Q_PROPERTY(QString icon WRITE SetIcon)
    QML_ELEMENT

private:
    QAction* action_;

public:
    TrayMenuItem(QObject* parent = nullptr);
    ~TrayMenuItem() override;

    void SetText(const QString& text);
    void SetIcon(const QString& icon);

    QString GetText() const;
    QIcon GetIcon() const;

    QAction* GetAction() const;

signals:
    void clicked(bool checked);
};