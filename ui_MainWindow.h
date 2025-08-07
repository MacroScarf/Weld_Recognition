/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenRobx;
    QAction *actionInsertpath;
    QAction *actionCompile;
    QAction *actionSimulate;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1139, 778);
        actionOpenRobx = new QAction(MainWindow);
        actionOpenRobx->setObjectName(QString::fromUtf8("actionOpenRobx"));
        actionInsertpath = new QAction(MainWindow);
        actionInsertpath->setObjectName(QString::fromUtf8("actionInsertpath"));
        actionCompile = new QAction(MainWindow);
        actionCompile->setObjectName(QString::fromUtf8("actionCompile"));
        actionSimulate = new QAction(MainWindow);
        actionSimulate->setObjectName(QString::fromUtf8("actionSimulate"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1139, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PQKit QT Sample", nullptr));
        actionOpenRobx->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\267\245\347\250\213", nullptr));
        actionInsertpath->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\350\275\250\350\277\271", nullptr));
        actionCompile->setText(QApplication::translate("MainWindow", "\347\274\226\350\257\221", nullptr));
        actionSimulate->setText(QApplication::translate("MainWindow", "\344\273\277\347\234\237", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
