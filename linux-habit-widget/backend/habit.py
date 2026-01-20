import subprocess
from PyQt5.QtCore import QObject, pyqtSignal

class Backend(QObject):
    streakUpdated = pyqtSignal(int)

    def mark_done(self):
        result = subprocess.check_output(["./scripts/habit_engine", "add"])
        self.streakUpdated.emit(int(result))

    def reset(self):
        result = subprocess.check_output(["./scripts/habit_engine", "reset"])
        self.streakUpdated.emit(int(result))
