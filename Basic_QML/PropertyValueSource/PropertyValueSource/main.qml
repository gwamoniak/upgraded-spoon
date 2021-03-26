import QtQuick 2.12
import QtQuick.Window 2.12
import RandomUtil 1.0


Window {
    width: 1200
    height: 800
    visible: true
    title: qsTr("Property value source demo")


    Rectangle{
        id: mRect
        width: 300
        height: 300
        color: "dodgerblue"
        RandomNumber on radius {
            maxValue: 100
        }

    }
}
