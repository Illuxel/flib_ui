import QtQuick
import forward.ui as Forward

Forward.TrayMenuWrapper {
    default property list<QtObject> items
    menuItems: items
}