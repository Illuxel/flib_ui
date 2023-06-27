import QtQuick
import QtQuick.Controls

Dialog {
    id: messageDialog

    property alias message: messageLabel.text

    Label {
        id: messageLabel

    }
}
