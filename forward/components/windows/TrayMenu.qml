import QtQuick

import forward.ui as Client

Client.TrayMenuWrapper {
    default property list<QtObject> items
    menuItems: items
}