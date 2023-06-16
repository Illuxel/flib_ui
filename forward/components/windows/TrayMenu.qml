import QtQuick

import forward.ui as Fl

Fl.TrayMenuWrapper {
    default property list<QtObject> items
    menuItems: items
}