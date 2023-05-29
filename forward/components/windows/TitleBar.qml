import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
    id: bar

    signal barDragged(bool active)

    signal barClicked(var mouse)
    signal barDoubleClicked(var mouse)

    signal hideBtnClicked()
    signal maximizeBtnClicked()
    signal closeBtnClicked()

    property var border
    property Item contentItem

    property alias icon: icon.source
    property alias title: label.text

    ToolBar {
        anchors.fill: parent

        anchors.topMargin: border
        anchors.leftMargin: border
        anchors.rightMargin: border

        MouseArea {
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            anchors.fill: parent
            anchors.rightMargin: 3 * close.width // 3 windows button

            DragHandler {
                target: null
                acceptedButtons: Qt.LeftButton
                cursorShape: Qt.ClosedHandCursor

                onActiveChanged: bar.barDragged(active)
            }

            onClicked: (mouse)=> {
                bar.barClicked(mouse)
            }
            onDoubleClicked: (mouse)=> {
                bar.barDoubleClicked(mouse)
            }
        }

        RowLayout {
            spacing: 0
            anchors.fill: parent

            Item { Layout.fillWidth: true }
            Item {
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignCenter

                RowLayout {
                    spacing: 10
                    anchors.fill: parent
                    Image {
                        id: icon
                        asynchronous: true
                        Layout.alignment: Qt.AlignCenter
                    }
                    Label {
                        id: label
                        Layout.alignment: Qt.AlignCenter
                    }    
                }
            }
            Item { Layout.fillWidth: true }

            ToolButton {
                id: hide
                text: "━"
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignRight
                
                onClicked: bar.hideBtnClicked()
            }
            ToolButton {
                id: max
                text: "⊠"
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignRight

                onClicked: bar.maximizeBtnClicked()
            }
            ToolButton {
                id: close
                text: "✕"
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignRight

                onClicked: bar.closeBtnClicked()
            }
        }
    }
}