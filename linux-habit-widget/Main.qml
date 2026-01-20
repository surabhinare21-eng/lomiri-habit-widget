import QtQuick 2.12
import Lomiri.Components 1.3

MainView {
    width: units.gu(40)
    height: units.gu(60)
    applicationName: "habit.widget"

    Page {
        header: PageHeader { title: "Habit Streak" }

        Column {
            anchors.centerIn: parent
            spacing: units.gu(2)

            Label {
                id: streakLabel
                text: "Streak: 0 days"
                fontSize: "large"
            }

            Button {
                text: "Done Today"
                onClicked: backend.mark_done()
            }

            Button {
                text: "Reset"
                onClicked: backend.reset()
            }
        }
    }

    Connections {
        target: backend
        function onStreakUpdated(value) {
            streakLabel.text = "Streak: " + value + " days"
        }
    }
}


