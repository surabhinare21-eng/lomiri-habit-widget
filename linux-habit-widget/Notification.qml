import Lomiri.Components 1.3

Dialog {
    id: dialog
    title: "Habit Tracker"

    Label {
        anchors.centerIn: parent
        text: message
    }

    Button {
        text: "OK"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: PopupUtils.close(dialog)
    }
}
