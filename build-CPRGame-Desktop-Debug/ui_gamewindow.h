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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *AED;
    QLabel *Scenario;
    QLabel *HowTo;
    QLabel *Patient;
    QRadioButton *radioButton;
    QDialogButtonBox *buttonBox;
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
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(880, 270, 89, 25));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(880, 70, 89, 25));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(880, 120, 89, 25));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(880, 170, 89, 25));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(880, 220, 89, 25));
        AED = new QLabel(centralWidget);
        AED->setObjectName(QStringLiteral("AED"));
        AED->setGeometry(QRect(880, 430, 100, 100));
        Scenario = new QLabel(centralWidget);
        Scenario->setObjectName(QStringLiteral("Scenario"));
        Scenario->setGeometry(QRect(0, 0, 250, 100));
        Scenario->setAutoFillBackground(true);
        HowTo = new QLabel(centralWidget);
        HowTo->setObjectName(QStringLiteral("HowTo"));
        HowTo->setGeometry(QRect(518, 0, 250, 100));
        HowTo->setTextFormat(Qt::PlainText);
        Patient = new QLabel(centralWidget);
        Patient->setObjectName(QStringLiteral("Patient"));
        Patient->setGeometry(QRect(0, 0, 1024, 720));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(880, 380, 112, 23));
        buttonBox = new QDialogButtonBox(centralWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(320, 280, 166, 25));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        GameWindow->setCentralWidget(centralWidget);
        Patient->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        AED->raise();
        Scenario->raise();
        HowTo->raise();
        radioButton->raise();
        buttonBox->raise();
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
        pushButton->setText(QApplication::translate("GameWindow", "Give Breaths", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("GameWindow", "Check Responsiveness", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("GameWindow", "Call 911", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("GameWindow", "Check for pulse/breathing", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("GameWindow", "Give Compressions", Q_NULLPTR));
        AED->setText(QApplication::translate("GameWindow", "AED ", Q_NULLPTR));
        Scenario->setText(QApplication::translate("GameWindow", "Current Scenario", Q_NULLPTR));
        HowTo->setText(QApplication::translate("GameWindow", "HOW TO", Q_NULLPTR));
        Patient->setText(QApplication::translate("GameWindow", "There will be the picture of the patient here", Q_NULLPTR));
        radioButton->setText(QApplication::translate("GameWindow", "RadioButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
