/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *my_plot;
    QListWidget *listWidget;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_2;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_criar_planilha;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setWindowOpacity(1.000000000000000);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextOnly);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        my_plot = new QCustomPlot(centralwidget);
        my_plot->setObjectName(QString::fromUtf8("my_plot"));
        my_plot->setGeometry(QRect(350, 60, 440, 370));
        my_plot->setMaximumSize(QSize(800, 800));
        my_plot->setStyleSheet(QString::fromUtf8("QCustomPlot{\n"
"	background-color: transparent;\n"
"\n"
"}"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 90, 301, 301));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(320, 60, 31, 421));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(-30, 40, 1031, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-40, 0, 1191, 51));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"    color: #FFF;\n"
"    background: #404E82;\n"
"    padding: 1px 4px 0px 4px;\n"
"    position: relative;\n"
"    border-bottom: 3px solid #C4D2EB;\n"
"    text-align: center;\n"
"    margin: 0 auto;\n"
"    display: block;\n"
"	font-size:20px;\n"
"	font-family:Arial;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 321, 16));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font-size:14px;\n"
"}"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 390, 151, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_criar_planilha = new QPushButton(layoutWidget);
        btn_criar_planilha->setObjectName(QString::fromUtf8("btn_criar_planilha"));
        btn_criar_planilha->setEnabled(true);
        btn_criar_planilha->setMinimumSize(QSize(0, 20));
        btn_criar_planilha->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #404E82;\n"
"	border-radius: 40px;\n"
"    color: white;\n"
"	font-weight: 500;\n"
"	font-size: 12px;\n"
"	font-family: Arial;\n"
"}"));

        horizontalLayout->addWidget(btn_criar_planilha);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 310, 47, 13));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Projeto POO", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Escolha componentes para observar as situa\303\247\303\265es ", nullptr));
        btn_criar_planilha->setText(QCoreApplication::translate("MainWindow", "Mostrar dados", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
