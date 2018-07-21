#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtWidgets>
#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include <QFontDatabase>
#include <QList>
#include <QModelIndex>
#include <QTreeView>
#include <QFileSystemModel>
#include <QStandardItemModel>
#include <QStandardItem>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget w;
    w.setStyleSheet("background-color: #ccc;");

    // Прописываем шрифты
    QFontDatabase::addApplicationFont(QCoreApplication::applicationDirPath() + "/fonts/oswald-regular.ttf");
    QFontDatabase::addApplicationFont(QCoreApplication::applicationDirPath() + "/fonts/pt_serif-regular.ttf");

    // Создаем основные слои раскладки
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
    layout5->setSpacing(0);
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
    QWidget* header = new QWidget(&w);
    header->setFixedHeight(80);
    header->setStyleSheet("background-color: #000;");
    header->setWindowFlags(Qt::FramelessWindowHint);

    // Footer
    QWidget* footer = new QWidget;
    footer->setFixedHeight(30);
    footer->setStyleSheet("background-color: #000;");
    footer->setWindowFlags(Qt::FramelessWindowHint);

    // MiddleLeft
    QWidget* middleLeft = new QWidget;
    middleLeft->setFixedWidth(320);
    middleLeft->setStyleSheet("background-color: #000;");
    middleLeft->setWindowFlags(Qt::FramelessWindowHint);

    // MiddleMiddle    
    QWidget* middleMiddle = new QWidget;
    middleMiddle->setStyleSheet("background-color: #000; border: none;");
    middleMiddle->setWindowFlags(Qt::FramelessWindowHint);
    QScrollArea* centerArea = new QScrollArea;
    layout5->addWidget(centerArea);
    layout5->setMargin(0);
    centerArea->setStyleSheet("background-color: #000; border: none;");
    QVBoxLayout* layout25 = new QVBoxLayout;
    centerArea->setLayout(layout25);
    centerArea->setWindowFlags(Qt::FramelessWindowHint);
    QTextBrowser* center = new QTextBrowser;
    center->setStyleSheet("background-color: #000; color: #fff; font-family: Oswald; font-weight: 400; font-size: 16px; line-height: 22px;");
    center->setWindowFlags(Qt::FramelessWindowHint);
    layout25->addWidget(center);
    layout25->setSpacing(0);
    layout25->setMargin(0);

    // MiddleRight
    QWidget* middleRight = new QWidget;
    middleRight->setFixedWidth(320);
    middleRight->setStyleSheet("background-color: #000;");
    middleRight->setWindowFlags(Qt::FramelessWindowHint);

    // Размещение виджетов в слои
    layout1->addWidget(header);
    layout3->addWidget(footer);
    layout4->addWidget(middleLeft);
    //layout5->addWidget(middleMiddle);
    layout6->addWidget(middleRight);

    // Наполнение header'а
    QHBoxLayout* layout7 = new QHBoxLayout;
    header->setLayout(layout7);
    QLabel* name = new QLabel("Personal Knowlege Base");
    name->setStyleSheet("color: #fff; font-family: 'Oswald'; font-size: 28px");
    QLabel *logo = new QLabel();
    logo->setMaximumSize(80, 50);
    logo->setStyleSheet("margin-left: 10px; margin-right: 0px;");
    //qDebug() << "Path:" << QDir::currentPath();
    logo->setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/img/logo.svg"));
    layout7->addWidget(logo);
    layout7->addWidget(name);

    // Наполнение footer'а
    QHBoxLayout* layout8 = new QHBoxLayout;
    layout8->setMargin(0);
    footer->setLayout(layout8);
    layout8->setAlignment(Qt::AlignCenter);
    QLabel* copyright = new QLabel("© Oleg Mishutin, 2018");
    copyright->setStyleSheet("color: #fff; font-family: 'PT Serif'; font-size: 11px;");
    layout8->addWidget(copyright);

    // Наполнение MiddleMiddle
    /*
    QVBoxLayout* layout9 = new QVBoxLayout;
    middleMiddle->setLayout(layout9);
    QLabel* slogan = new QLabel("Knowledge is power.");
    slogan->setStyleSheet("color: #fff; font-family: 'Oswald'; font-size: 50px; line-height: 64px");
    QLabel *author = new QLabel("Francis Bacon (1561-1626)");
    author->setStyleSheet("color: #fff; font-family: 'PT Serif'; font-size: 20px; line-height: 44px; font-style: italic; margin-left: 130px; margin-top: 20px;");
    layout9->setAlignment(Qt::AlignCenter);
    layout9->addWidget(slogan);
    layout9->addWidget(author);
    */

    // Наполнение MiddleRight
    QVBoxLayout* layout10 = new QVBoxLayout;
    middleRight->setLayout(layout10);
    // Омнибокс
    QLineEdit* omnibox = new QLineEdit;
    omnibox->setStyleSheet("max-width: 260px; height: 50px; padding-left: 10px; padding-right: 10px; margin-left: 10px; color: #000; font-family: 'PT Serif'; font-size: 16px; line-height: 24px; background-color: #ffffef; border-radius: 2px; border: 2px solid #ffbb00");
    // Надпись над омнибоксом
    QLabel* omniboxLabel = new QLabel("Wanted:");
    omniboxLabel->setStyleSheet("color: #fff; font-family: 'PT Serif'; font-size: 24px; line-height: 60px; margin-left: 6px; margin-top: 20px;");
    // Кнопка
    QPushButton* btnSearch = new QPushButton("Search");
    btnSearch->setStyleSheet("QPushButton{max-width: 280px; height: 54px; margin-left: 10px; background-color: #ffbb00; color: #000; border: 2px solid #ffbb00; border-radius: 2px; font-family: 'Oswald'; font-size: 26px; margin-top: 20px;}" "QPushButton:hover{background-color: #ffaa00; border: 2px solid #ffaa00;}");
    //btnSearch->installEventFilter(this);
    btnSearch->setCursor(Qt::PointingHandCursor);
    layout10->setAlignment(Qt::AlignTop);
    layout10->addWidget(omniboxLabel);
    layout10->addWidget(omnibox);
    layout10->addWidget(btnSearch);

    // Наполнение MiddleLeft
    QVBoxLayout* layout11 = new QVBoxLayout;
    layout11->setSpacing(0);
    layout11->setMargin(0);
    layout11->setAlignment(Qt::AlignTop);
    middleLeft->setLayout(layout11);
    middleLeft->setContentsMargins(0,0,0,0);
    QHBoxLayout* layout12 = new QHBoxLayout;
    layout12->setAlignment(Qt::AlignLeft);
    layout12->setSpacing(0);
    layout12->setMargin(0);
    layout11->addLayout(layout12);
    QLabel* toc = new QLabel("Content");
    toc->setContentsMargins(0,0,0,0);
    toc->setStyleSheet("padding-right: 10px; color: #fff; font-family: 'PT Serif'; font-weight: 400; font-size: 28px; line-height: 30px; padding-bottom: 13px;");
    QLabel* ctrlBook = new QLabel();
    ctrlBook->setContentsMargins(0,0,0,0);
    ctrlBook->setStyleSheet("margin-bottom: 6px");
    ctrlBook->setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/img/book-closed.svg"));
    layout12->addWidget(toc);
    layout12->addWidget(ctrlBook);

    QScrollArea* scrollingSideBar = new QScrollArea;
    scrollingSideBar->setFrameShape(QFrame::NoFrame); // убрал рамку вокруг виджета со скроллом
    layout11->addWidget(scrollingSideBar);
    // Меню
    QVBoxLayout* layout14 = new QVBoxLayout;
    layout14->setSpacing(0);
    layout14->setMargin(0);
    layout14->setAlignment(Qt::AlignTop);
    scrollingSideBar->setLayout(layout14);

    //scrollingSideBar->setLayout(layout15);

    QFileSystemModel *model = new QFileSystemModel();
    model->setRootPath(QDir::currentPath());
    QTreeView *tree = new QTreeView();
    tree->setModel(model);
    tree->setRootIndex(model->index(QCoreApplication::applicationDirPath() + "/pkb_db"));
    tree->hideColumn(1);
    tree->hideColumn(2);
    tree->hideColumn(3);
    tree->setHeaderHidden(true);
    tree->setStyleSheet("color: #ffc0cb; font-family: 'Oswald'; font-size: 14px; line-height: 16px");
    tree->setFrameShape(QFrame::NoFrame);
    layout14->addWidget(tree);
    QModelIndex index1 = model->index(QCoreApplication::applicationDirPath() + "/pkb_db/I. Web programming/001. Roadmaps/000. Roadmaps.html");

    //tree->setCurrentIndex(model->index(QCoreApplication::applicationDirPath() + "/pkb_db/I. Web programming/001. Roadmaps/000. Roadmaps.html"));
    center->setSource(QUrl("file:///" + QCoreApplication::applicationDirPath() + "/pkb_db/I. Web programming/001. Roadmaps/000. Roadmaps.html"));
    center->hide();

    QString filepath1 = model->filePath(index1);

    qDebug() << "filename1:" << filepath1;
    qDebug() << "index1:" << index1;
    //QString filepath = model->fileName(index1);
    //QStandardItem *item = model->itemFromIndex(model->mapToSource(index));
    QObject::connect(tree, SIGNAL(clicked(const QModelIndex&)), center, SLOT(show()));
    //QObject::connect(item, SIGNAL(clicked(const QModelIndex&)), center, SLOT(show(const QModelIndex &model)));
    //QObject::connect(middleMiddle, SIGNAL(activated(const QModelIndex&)), tree, SLOT(setCurrentIndex(const QModelIndex&)));
    //QObject::connect(middleMiddle, SIGNAL(activated(const QModelIndex&)), tree, SLOT(setRootIndex(const QModelIndex&)));

    // Удаление рамки внутри главного окна, задание минимальных размеров
    w.layout()->setContentsMargins(0, 0, 0, 0);
    w.setMinimumWidth(1200);
    w.setMinimumHeight(800);
    w.showMaximized();

    return app.exec();
}
