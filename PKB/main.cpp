#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lbl;
    lbl.setPixmap(QPixmap("d:/Work/PKB/PKB/img/avatar.jpeg"));
    lbl.show();
    return a.exec();
}
