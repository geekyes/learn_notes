
# coding = utf-8

#================================================================
#                source for learn_notes
#
#   filename   : hello_world.py
#   author     : chenjiang
#   date       : 2019-01-12
#   description: pyqt5 hello world
#
#================================================================

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton
from PyQt5.QtCore import QCoreApplication

class hello_world(QWidget):
    def __init__(self):
        super().__init__()
        self.init_UI()

    def init_UI(self):
        #  param: x, y, width, heihgt
        self.setGeometry(300, 300, 500, 200)
        self.setWindowTitle('hello world')
        qbtn = QPushButton('退出', self)
        qbtn.setGeometry(80, 80, 100, 50)
        qbtn.clicked.connect(QCoreApplication.instance().quit)
        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    hw = hello_world()
    sys.exit(app.exec_())
