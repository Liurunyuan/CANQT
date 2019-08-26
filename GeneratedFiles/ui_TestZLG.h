/********************************************************************************
** Form generated from reading UI file 'TestZLG.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTZLG_H
#define UI_TESTZLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestZLGClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestZLGClass)
    {
        if (TestZLGClass->objectName().isEmpty())
            TestZLGClass->setObjectName(QString::fromUtf8("TestZLGClass"));
        TestZLGClass->resize(600, 400);
        menuBar = new QMenuBar(TestZLGClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        TestZLGClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestZLGClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TestZLGClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TestZLGClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TestZLGClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TestZLGClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TestZLGClass->setStatusBar(statusBar);

        retranslateUi(TestZLGClass);

        QMetaObject::connectSlotsByName(TestZLGClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestZLGClass)
    {
        TestZLGClass->setWindowTitle(QCoreApplication::translate("TestZLGClass", "TestZLG", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestZLGClass: public Ui_TestZLGClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTZLG_H
