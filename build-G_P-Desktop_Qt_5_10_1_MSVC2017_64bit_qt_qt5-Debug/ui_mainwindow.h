/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *input;
    QPushButton *pushButton;
    QLabel *label1;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QListView *listView_7;
    QListView *listView_9;
    QListView *listView_10;
    QListView *listView_11;
    QListView *listView_12;
    QListView *listView_13;
    QListView *listView_14;
    QListView *listView_15;
    QListView *listView_16;
    QListView *listView_6;
    QLabel *label1_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1080, 597);
        MainWindow->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(40, 420, 195, 31));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        input = new QPushButton(formLayoutWidget);
        input->setObjectName(QStringLiteral("input"));
        input->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, input);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pushButton);

        label1 = new QLabel(centralWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(80, 10, 71, 31));
        label1->setStyleSheet(QLatin1String("background-color: rgb(199, 199, 199);\n"
"color: rgb(0, 0, 0);"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(290, 40, 791, 461));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 768, 459));
        listView_7 = new QListView(scrollAreaWidgetContents);
        listView_7->setObjectName(QStringLiteral("listView_7"));
        listView_7->setGeometry(QRect(10, 10, 201, 201));
        listView_9 = new QListView(scrollAreaWidgetContents);
        listView_9->setObjectName(QStringLiteral("listView_9"));
        listView_9->setGeometry(QRect(290, 10, 201, 201));
        listView_10 = new QListView(scrollAreaWidgetContents);
        listView_10->setObjectName(QStringLiteral("listView_10"));
        listView_10->setGeometry(QRect(550, 10, 201, 201));
        listView_11 = new QListView(scrollAreaWidgetContents);
        listView_11->setObjectName(QStringLiteral("listView_11"));
        listView_11->setGeometry(QRect(550, 240, 201, 201));
        listView_12 = new QListView(scrollAreaWidgetContents);
        listView_12->setObjectName(QStringLiteral("listView_12"));
        listView_12->setGeometry(QRect(290, 240, 201, 201));
        listView_13 = new QListView(scrollAreaWidgetContents);
        listView_13->setObjectName(QStringLiteral("listView_13"));
        listView_13->setGeometry(QRect(10, 240, 201, 201));
        listView_14 = new QListView(scrollAreaWidgetContents);
        listView_14->setObjectName(QStringLiteral("listView_14"));
        listView_14->setGeometry(QRect(10, 450, 201, 201));
        listView_15 = new QListView(scrollAreaWidgetContents);
        listView_15->setObjectName(QStringLiteral("listView_15"));
        listView_15->setGeometry(QRect(290, 450, 201, 201));
        listView_16 = new QListView(scrollAreaWidgetContents);
        listView_16->setObjectName(QStringLiteral("listView_16"));
        listView_16->setGeometry(QRect(550, 450, 201, 201));
        scrollArea->setWidget(scrollAreaWidgetContents);
        listView_6 = new QListView(centralWidget);
        listView_6->setObjectName(QStringLiteral("listView_6"));
        listView_6->setGeometry(QRect(10, 50, 251, 301));
        label1_4 = new QLabel(centralWidget);
        label1_4->setObjectName(QStringLiteral("label1_4"));
        label1_4->setGeometry(QRect(690, 10, 71, 31));
        label1_4->setStyleSheet(QLatin1String("background-color: rgb(199, 199, 199);\n"
"color: rgb(0, 0, 0);"));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1080, 26));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\214\273\345\255\246\345\275\261\345\203\217\346\243\200\347\264\242\347\263\273\347\273\237v1.0                Inkc", nullptr));
        input->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\243\200\347\264\242", nullptr));
        label1->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\345\233\276\345\203\217", nullptr));
        label1_4->setText(QApplication::translate("MainWindow", "\346\243\200\347\264\242\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
