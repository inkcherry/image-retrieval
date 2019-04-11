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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QWidget *layoutWidget;
    QVBoxLayout *inpuy;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *input_image_lable;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *input_count;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *widget_2;
    QWidget *layoutWidget_2;
    QVBoxLayout *output;
    QHBoxLayout *title;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *content;
    QHBoxLayout *but;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1043, 733);
        MainWindow->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("background-color: rgb(102, 102, 102);\n"
"border-width: 2px;\n"
"\n"
"border-style: solid;\n"
"border-color: rgb(55, 169, 200);\n"
""));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 191, 561));
        inpuy = new QVBoxLayout(layoutWidget);
        inpuy->setSpacing(6);
        inpuy->setContentsMargins(11, 11, 11, 11);
        inpuy->setObjectName(QStringLiteral("inpuy"));
        inpuy->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(6666666, 16777215));
        label->setStyleSheet(QStringLiteral("color: rgb(102, 204, 204);"));

        horizontalLayout_7->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        inpuy->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        input_image_lable = new QLabel(layoutWidget);
        input_image_lable->setObjectName(QStringLiteral("input_image_lable"));
        input_image_lable->setStyleSheet(QLatin1String("border-width: 3px;\n"
"border-style: solid;\n"
"border-color: rgb(51, 102, 102);\n"
""));

        verticalLayout_2->addWidget(input_image_lable);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color: rgb(51, 153, 204);"));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_4);

        input_count = new QLineEdit(layoutWidget);
        input_count->setObjectName(QStringLiteral("input_count"));

        verticalLayout_2->addWidget(input_count);

        verticalLayout_2->setStretch(0, 10);
        verticalLayout_2->setStretch(2, 2);

        horizontalLayout_6->addLayout(verticalLayout_2);


        inpuy->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("background-color: rgb(51, 153, 204);\n"
"background-color: rgb(51, 153, 204);"));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(51, 153, 204);"));

        horizontalLayout_3->addWidget(pushButton);


        inpuy->addLayout(horizontalLayout_3);

        inpuy->setStretch(0, 1);
        inpuy->setStretch(1, 7);
        inpuy->setStretch(2, 1);

        horizontalLayout_2->addWidget(widget);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        layoutWidget_2 = new QWidget(widget_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 0, 851, 561));
        output = new QVBoxLayout(layoutWidget_2);
        output->setSpacing(6);
        output->setContentsMargins(11, 11, 11, 11);
        output->setObjectName(QStringLiteral("output"));
        output->setContentsMargins(0, 0, 0, 0);
        title = new QHBoxLayout();
        title->setSpacing(6);
        title->setObjectName(QStringLiteral("title"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        title->addItem(horizontalSpacer_4);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        title->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        title->addItem(horizontalSpacer_3);


        output->addLayout(title);

        content = new QHBoxLayout();
        content->setSpacing(6);
        content->setObjectName(QStringLiteral("content"));

        output->addLayout(content);

        but = new QHBoxLayout();
        but->setSpacing(6);
        but->setObjectName(QStringLiteral("but"));

        output->addLayout(but);

        output->setStretch(0, 1);
        output->setStretch(1, 10);
        output->setStretch(2, 1);

        horizontalLayout_2->addWidget(widget_2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 4);

        horizontalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1043, 26));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\214\273\345\255\246\345\275\261\345\203\217\346\243\200\347\264\242\347\263\273\347\273\237v1.0                Inkc", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\243\200\347\264\242\345\233\276\345\203\217", nullptr));
        input_image_lable->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\345\233\276\345\203\217", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\243\200\347\264\242\346\225\260\351\207\217", nullptr));
        input_count->setText(QApplication::translate("MainWindow", "5", nullptr));
        input_count->setPlaceholderText(QApplication::translate("MainWindow", "5", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\350\275\275\345\205\245\345\233\276\345\203\217", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\243\200\347\264\242", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\243\200\347\264\242\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
