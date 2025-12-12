import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Qml CV Reader")

    function hotReload() {
        loader.sourceComponent = undefined
        loader.source = ""
        $Engine.clearCache()
        loader.source = "MainFrame.qml"
    }

    Shortcut {
        sequence: '`'
        onActivated: hotReload()
    }

    Component {
        id: mainFrameComp
        MainFrame {}
    }

    Loader {
        id: loader
        anchors.fill: parent
        sourceComponent: mainFrameComp
    }
}
