import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Connection Ping Check")

    property bool isConnectedProp: false


    Connections{
        target: connectionObj
        onIsConnected: isConnectedProp = val

    }

    Rectangle{
        anchors.fill: parent

        Image {
            anchors.centerIn: parent
            id: img
            width: 50
            height:50
            source: isConnectedProp ? "qrc:/led-green-hi.png" : "qrc:/redLED.png"
        }

        Text {
            id: txt
            anchors.top: img.bottom
            anchors.left: img.left
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            text:isConnectedProp? qsTr("Connected!"):qsTr("Disconnected!")
            anchors.topMargin: 5
        }

    }
}
