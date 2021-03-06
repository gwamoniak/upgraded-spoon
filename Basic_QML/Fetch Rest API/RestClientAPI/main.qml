import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Fetch API")

    ColumnLayout{
        anchors.fill: parent
        spacing: 0


        ListView{
            id: mListView
            model: myModel
            delegate: Rectangle{
                width: parent.width
                height: textId.implicitHeight+30
                color: "lightgreen"
                border.color: "yellowgreen"
                radius: 5

                Text {
                    id: textId
                    width: parent.width
                    height: parent.height
                    anchors.centerIn: parent
                    text: modelData
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        SpinBox{
            id:spinBoxId
            Layout.fillWidth: true
            value: 10
        }

        Button{
            id: mButton1
            text:"Fetch"
            Layout.fillWidth: true
            onClicked: {
                Wrapper.fetchPosts(spinBoxId.value)
            }
        }

        Button{
            id: mButton2
            text:"RemoveLast"
            Layout.fillWidth: true
            onClicked: {
                Wrapper.removeLast()
            }
        }


    }
}

