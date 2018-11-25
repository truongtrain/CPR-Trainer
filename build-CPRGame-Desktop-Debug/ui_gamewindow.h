/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Breath;
    QPushButton *Call911;
    QPushButton *CPR;
    QLabel *AED;
    QLabel *Scenario;
    QLabel *HowTo;
    QLabel *Patient;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *Check;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QStringLiteral("GameWindow"));
        GameWindow->resize(1024, 720);
        centralWidget = new QWidget(GameWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Breath = new QPushButton(centralWidget);
        Breath->setObjectName(QStringLiteral("Breath"));
        Breath->setGeometry(QRect(850, 170, 111, 25));
        Call911 = new QPushButton(centralWidget);
        Call911->setObjectName(QStringLiteral("Call911"));
        Call911->setGeometry(QRect(850, 50, 111, 25));
        CPR = new QPushButton(centralWidget);
        CPR->setObjectName(QStringLiteral("CPR"));
        CPR->setGeometry(QRect(850, 110, 111, 25));
        AED = new QLabel(centralWidget);
        AED->setObjectName(QStringLiteral("AED"));
        AED->setGeometry(QRect(780, 480, 160, 180));
        Scenario = new QLabel(centralWidget);
        Scenario->setObjectName(QStringLiteral("Scenario"));
        Scenario->setGeometry(QRect(20, 40, 200, 200));
        Scenario->setAutoFillBackground(true);
        HowTo = new QLabel(centralWidget);
        HowTo->setObjectName(QStringLiteral("HowTo"));
        HowTo->setEnabled(true);
        HowTo->setGeometry(QRect(20, 260, 200, 200));
        HowTo->setAutoFillBackground(true);
        HowTo->setTextFormat(Qt::PlainText);
        Patient = new QLabel(centralWidget);
        Patient->setObjectName(QStringLiteral("Patient"));
        Patient->setGeometry(QRect(270, 50, 450, 640));
        Patient->setAutoFillBackground(true);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(780, 420, 89, 25));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(780, 360, 89, 25));
        Check = new QPushButton(centralWidget);
        Check->setObjectName(QStringLiteral("Check"));
        Check->setGeometry(QRect(850, 230, 111, 41));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(910, 360, 89, 25));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(910, 420, 89, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(770, 60, 67, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(770, 100, 67, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(770, 170, 67, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(770, 240, 67, 17));
        GameWindow->setCentralWidget(centralWidget);
        Call911->raise();
        CPR->raise();
        Breath->raise();
        pushButton_6->raise();
        AED->raise();
        Patient->raise();
        Scenario->raise();
        HowTo->raise();
        pushButton_7->raise();
        Check->raise();
        pushButton_8->raise();
        pushButton_9->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        menuBar = new QMenuBar(GameWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 22));
        GameWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GameWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GameWindow->addToolBar(Qt::RightToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GameWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GameWindow->setStatusBar(statusBar);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "GameWindow", Q_NULLPTR));
        Breath->setText(QApplication::translate("GameWindow", "Give Breaths", Q_NULLPTR));
        Call911->setText(QApplication::translate("GameWindow", "Call 911", Q_NULLPTR));
        CPR->setText(QApplication::translate("GameWindow", "Do CPR", Q_NULLPTR));
        AED->setText(QApplication::translate("GameWindow", "AED ", Q_NULLPTR));
        Scenario->setText(QApplication::translate("GameWindow", "Current Scenario", Q_NULLPTR));
        HowTo->setText(QApplication::translate("GameWindow", "HOW TO", Q_NULLPTR));
        Patient->setText(QApplication::translate("GameWindow", "There will be the picture of the patient here", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("GameWindow", "on/off", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("GameWindow", "on/off", Q_NULLPTR));
        Check->setText(QApplication::translate("GameWindow", "Check \n"
"Responsiveness", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("GameWindow", "on/off", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("GameWindow", "on/off", Q_NULLPTR));
        label->setText(QApplication::translate("GameWindow", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("GameWindow", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("GameWindow", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("GameWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
