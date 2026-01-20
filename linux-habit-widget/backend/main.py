import sys
from PyQt5.QtGui import QGuiApplication
from PyQt5.QtQml import QQmlApplicationEngine
from habit import Backend

app = QGuiApplication(sys.argv)

engine = QQmlApplicationEngine()
backend = Backend()

# 🔑 THIS is the key line
engine.rootContext().setContextProperty("backend", backend)

engine.load("../Main.qml")

if not engine.rootObjects():
    sys.exit(-1)

sys.exit(app.exec_())
