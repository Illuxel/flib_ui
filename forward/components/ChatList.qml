import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import forward.ui as Client

ListView {
    id: chatList

    focus: true

    delegate: ItemDelegate {
        id: chatItem

        width: chatList.width
        height: row.implicitHeight

        // background: Rectangle {
        //     color: chatItem.down ? "#d6d6d6" : "#f6f6f6"
        //     border.color: "#26282a"
        //     border.width: 2
        // }

        RowLayout {
            id: row
            spacing: 8
            
            anchors.fill: parent

            Image { 
                id: avatar
                fillMode: Image.PreserveAspectFit
                source: userAvatar 

                Layout.fillHeight: true
                Layout.alignment: Qt.AlignVCenter
            }

            ColumnLayout {
                id: column
                spacing: 2

                Layout.fillWidth: true
                Layout.fillHeight: true
                
                Label { 
                    text: userName 
                    Layout.fillWidth: true
                }
                Label { 
                    text: lastMessage 
                    Layout.fillWidth: true
                }
            }
        }
    }
}