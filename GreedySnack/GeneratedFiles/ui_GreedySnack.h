/********************************************************************************
** Form generated from reading UI file 'GreedySnack.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GREEDYSNACK_H
#define UI_GREEDYSNACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GreedySnackClass
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GreedySnackClass)
    {
        if (GreedySnackClass->objectName().isEmpty())
            GreedySnackClass->setObjectName(QString::fromUtf8("GreedySnackClass"));
        GreedySnackClass->resize(600, 400);
        centralWidget = new QWidget(GreedySnackClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(160, 60, 256, 192));
        GreedySnackClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GreedySnackClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        GreedySnackClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GreedySnackClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GreedySnackClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GreedySnackClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GreedySnackClass->setStatusBar(statusBar);

        retranslateUi(GreedySnackClass);

        QMetaObject::connectSlotsByName(GreedySnackClass);
    } // setupUi

    void retranslateUi(QMainWindow *GreedySnackClass)
    {
        GreedySnackClass->setWindowTitle(QApplication::translate("GreedySnackClass", "GreedySnack", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GreedySnackClass: public Ui_GreedySnackClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GREEDYSNACK_H
