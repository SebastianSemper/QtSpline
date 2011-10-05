/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created: Wed Oct 5 13:43:32 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *button_go;
    QGraphicsView *view_canvas;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(810, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        button_go = new QPushButton(centralwidget);
        button_go->setObjectName(QString::fromUtf8("button_go"));
        button_go->setGeometry(QRect(0, 570, 89, 27));
        view_canvas = new QGraphicsView(centralwidget);
        view_canvas->setObjectName(QString::fromUtf8("view_canvas"));
        view_canvas->setEnabled(true);
        view_canvas->setGeometry(QRect(10, 10, 791, 551));
        view_canvas->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        view_canvas->setMouseTracking(true);
        view_canvas->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        button_go->setText(QApplication::translate("MainWindow", "Go", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
