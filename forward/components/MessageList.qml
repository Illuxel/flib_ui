import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

ListView {
    id: messageList

    signal clicked()
    signal doubleClicked()

    delegate: ItemDelegate {

        width: messageRow.implicitWidth
        height: messageRow.implicitHeight

        Row {
            id: messageRow
            spacing: 5

            Image {
                id: avatar
                width: 64
                height: 64
                source: model.userAvatar
            }

            Column {
                spacing: 5

                RowLayout {
                    spacing: 5

                    Label {
                        font.bold: true
                        font.pixelSize: 22
                        text: model.userName
                        textFormat: Text.RichText
                        Layout.leftMargin: 10
                    }
                    Label {
                        id: timestampText
                        text: model.timestamp // Qt.formatDateTime(, "d MMM hh:mm")
                        Layout.alignment: Qt.AlignRight
                    }
                }

                Rectangle {
                    id: messageBox
                    width: messageList.width - avatar.width - messageRow.spacing
                    height: messageText.implicitHeight + timestampText.implicitHeight

                    color: "transparent"

                    Label {
                        id: messageText
                        clip: true
                        text: model.message
                        textFormat: Text.RichText
                        font.pixelSize: 16
                        wrapMode: Label.WordWrap

                        anchors.fill: parent
                        anchors.margins: 10
                    }
                }
            }
        }

        onClicked: messageList.clicked()
        onDoubleClicked: messageList.doubleClicked()
    }

    ScrollBar.vertical: ScrollBar {}
}
