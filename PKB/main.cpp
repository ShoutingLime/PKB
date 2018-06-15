#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget w;
    w.setStyleSheet("background-color:#ccc;");

    // Создаем слои
    QVBoxLayout* layout0 = new QVBoxLayout;
    QHBoxLayout* layout1 = new QHBoxLayout;
    QHBoxLayout* layout2 = new QHBoxLayout;
    QHBoxLayout* layout3 = new QHBoxLayout;
    QVBoxLayout* layout4 = new QVBoxLayout;
    QVBoxLayout* layout5 = new QVBoxLayout;
    QVBoxLayout* layout6 = new QVBoxLayout;

    // Границы слоев
    layout0->setSpacing(1);
    layout1->setSpacing(1);
    layout2->setSpacing(1);
    layout3->setSpacing(1);
    layout4->setSpacing(1);
    layout5->setSpacing(1);
    layout6->setSpacing(1);

    // Раскладка слоев
    w.setLayout(layout0);
    w.setContentsMargins(1,1,1,1);
    layout0->addLayout(layout1);
    layout0->addLayout(layout2);
    layout0->addLayout(layout3);
    layout2->addLayout(layout4);
    layout2->addLayout(layout5);
    layout2->addLayout(layout6);

    // Header
    QWidget* header = new QWidget;
    header->setFixedHeight(80);
    header->setStyleSheet("background-color:#000;");
    header->setWindowFlags(Qt::FramelessWindowHint);

    // Footer
    QWidget* footer = new QWidget;
    footer->setFixedHeight(30);
    footer->setStyleSheet("background-color:#000;");
    footer->setWindowFlags(Qt::FramelessWindowHint);

    // MiddleLeft
    QWidget* middleLeft = new QWidget;
    middleLeft->setFixedWidth(300);
    middleLeft->setStyleSheet("background-color:#000;");
    middleLeft->setWindowFlags(Qt::FramelessWindowHint);

    // MiddleMiddle
    QWidget* middleMiddle = new QWidget;
    middleMiddle->setStyleSheet("background-color:#000;");
    middleMiddle->setWindowFlags(Qt::FramelessWindowHint);

    // MiddleRight
    QWidget* middleRight = new QWidget;
    middleRight->setFixedWidth(300);
    middleRight->setStyleSheet("background-color:#000;");
    middleRight->setWindowFlags(Qt::FramelessWindowHint);

    // Размещение виджетов в слои
    layout1->addWidget(header);
    layout3->addWidget(footer);
    layout4->addWidget(middleLeft);
    layout5->addWidget(middleMiddle);
    layout6->addWidget(middleRight);

    // Удаление рамки внутри главного окна, задание минимальных размеров
    w.layout()->setContentsMargins(0, 0, 0, 0);
    w.setMinimumWidth(1200);
    w.setMinimumHeight(800);
    w.showMaximized();

    return app.exec();
}
