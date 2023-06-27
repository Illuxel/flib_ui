import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import forward.ui as Client

ListView {
    id: chatList

    focus: true

    signal itemClicked(int index)

    delegate: ItemDelegate {

        width: chatList.width
        height: row.implicitHeight

        RowLayout {
            id: row
            spacing: 8
            
            anchors.fill: parent

            Image { 
                id: avatar

                width: 64
                height: 64

                source: userAvatar 

                fillMode: Image.PreserveAspectFit

                Layout.minimumWidth: 64
                Layout.margins: 5
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
            }

            ColumnLayout {
                id: column
                spacing: 2

                Layout.rightMargin: 6
                Layout.fillWidth: true
                Layout.fillHeight: true
                
                RowLayout {
                    spacing: 0

                    Layout.fillWidth: true

                    Label { 
                        clip: true
                        text: userName 
                        elide: Text.ElideRight
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignLeft
                    }
                    Label { 
                        text: timestamp
                        Layout.alignment: Qt.AlignRight
                    }
                }

                Label { 
                    clip: true
                    text: lastMessage
                    elide: Text.ElideRight
                    Layout.fillWidth: true
                }
            }
        }

        onClicked: { 
            itemClicked(index)
        }
    }
}