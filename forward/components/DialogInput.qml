import QtQuick
import QtQuick.Controls

Dialog {
    id: inputDialog

    default property list<QtObject> items
    property alias spacing: layout.spacing
    

    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
    parent: Overlay.overlay

    focus: true
    modal: true
    standardButtons: Dialog.Ok | Dialog.Cancel

    ColumnLayout {
        id: layout

        spacing: 20
        anchors.fill: parent
        children: items
    }
}