import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import com.upgraded_spoon 1.0
import error.upgraded_spoon 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Custom Types")

    Counter{
        id:mCounter
    }

    Column
    {
        anchors.centerIn: parent
        spacing: 10

        Rectangle
        {
           width: 200
           height: 200
           radius: 20
           color:(mCounter.count >= 0) ? "green" : "red"

           Text {
               id: mText
               text: mCounter.count
               anchors.centerIn: parent
               font.pointSize: 30
               color: "white"
           }
        }

        Button
        {
            width: 200
            text: "Start"
            onClicked: {
                mCounter.start()
                console.log(ErrorStatus.DEBUG)
            }
        }
        Button
        {
            width: 200
            text: "Stop"
            onClicked: {
                mCounter.stop()
            }

        }
        Button
        {
            width: 200
            text: "Up"
            onClicked: {
                mCounter.Counting = CountingStatus.UP
            }
        }
        Button
        {
            width: 200
            text: "Down"
            onClicked: {
                mCounter.Counting = CountingStatus.DOWN
            }

        }
    }
}
