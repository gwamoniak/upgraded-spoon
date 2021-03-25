import QtQuick 2.12
import QtQuick.Window 2.12

import Timing 1.0
import People 1.0

Window {
    width: 1200
    height: 800
    visible: true
    title: qsTr("Attached Properties")

    Person{
        id: person
        name: "Lewandowski"
        age: 33
        Timer.running: true
        Timer.interval: 3000
        Timer.onTimerOut:{
            console.log("Timer form Persone opbject")
        }

    }

    Rectangle{
        id: mRect
        width: 200
        height: 200
        color: "blue"
        Timer.running: true
        Timer.interval: 2000
        Timer.onTimerOut:{
            console.log("Timer form Persone opbject")
        }

    }
}
