import QtQuick
import QtQuick.Controls

Dialog {
    id: messageDialog

    x: (parent.width - width) / 2
    y: (parent.height - height) / 2

    property alias message: messageLabel.text

    Label {
        id: messageLabel
    }
}