/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
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
    QPushButton *Call911;
    QPushButton *CPR;
    QLabel *Scenario;
    QLabel *HowTo;
    QLabel *Patient;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *Check;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *Check_2;
    QPushButton *CPR_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QStringLiteral("GameWindow"));
        GameWindow->resize(1024, 720);
        QFont font;
        font.setPointSize(11);
        GameWindow->setFont(font);
        GameWindow->setIconSize(QSize(84, 110));
        centralWidget = new QWidget(GameWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Call911 = new QPushButton(centralWidget);
        Call911->setObjectName(QStringLiteral("Call911"));
        Call911->setGeometry(QRect(850, 60, 111, 25));
        Call911->setStyleSheet(QLatin1String("QPushButton {\n"
"background: rgb(238, 39, 39);\n"
"color: white;\n"
"border: 5px rgb(196, 32, 38);\n"
"border-radius: 5px;\n"
"} \n"
"\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background: rgb(255, 80, 80);\n"
"}\n"
""));
        CPR = new QPushButton(centralWidget);
        CPR->setObjectName(QStringLiteral("CPR"));
        CPR->setGeometry(QRect(850, 150, 111, 25));
        CPR->setStyleSheet(QLatin1String("QPushButton {\n"
"background: rgb(238, 39, 39);\n"
"color: white;\n"
"border: 5px rgb(196, 32, 38);\n"
"border-radius: 5px;\n"
"} \n"
"\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background: rgb(255, 80, 80);\n"
"}\n"
""));
        Scenario = new QLabel(centralWidget);
        Scenario->setObjectName(QStringLiteral("Scenario"));
        Scenario->setGeometry(QRect(20, 40, 200, 200));
        Scenario->setAutoFillBackground(false);
        Scenario->setStyleSheet(QLatin1String("color: white;\n"
"background: rgb(238, 39, 39);\n"
"border: 1px rgb(196, 32, 38);"));
        HowTo = new QLabel(centralWidget);
        HowTo->setObjectName(QStringLiteral("HowTo"));
        HowTo->setEnabled(true);
        HowTo->setGeometry(QRect(20, 260, 200, 200));
        HowTo->setAutoFillBackground(false);
        HowTo->setStyleSheet(QLatin1String("color: white;\n"
"background: rgb(238, 39, 39);\n"
"border: 1px rgb(196, 32, 38);"));
        HowTo->setTextFormat(Qt::PlainText);
        Patient = new QLabel(centralWidget);
        Patient->setObjectName(QStringLiteral("Patient"));
        Patient->setGeometry(QRect(270, 50, 450, 640));
        Patient->setAutoFillBackground(true);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(760, 420, 51, 51));
        pushButton_6->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_6->setToolTipDuration(5000);
        pushButton_6->setStyleSheet(QLatin1String("QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid white;\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/shock.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon);
        pushButton_6->setIconSize(QSize(72, 72));
        pushButton_6->setFlat(true);
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(760, 320, 51, 51));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid white;\n"
"}\n"
"\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/on.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon1);
        pushButton_7->setIconSize(QSize(72, 72));
        pushButton_7->setFlat(true);
        Check = new QPushButton(centralWidget);
        Check->setObjectName(QStringLiteral("Check"));
        Check->setGeometry(QRect(850, 230, 111, 41));
        Check->setStyleSheet(QLatin1String("QPushButton {\n"
"background: rgb(238, 39, 39);\n"
"color: white;\n"
"border: 5px rgb(196, 32, 38);\n"
"border-radius: 5px;\n"
"} \n"
"\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background: rgb(255, 80, 80);\n"
"}\n"
""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(770, 40, 71, 71));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/call.png")));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(770, 120, 71, 81));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/cpr.png")));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(770, 210, 67, 71));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/check.png")));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(880, 320, 84, 110));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/pads.png")));
        label_4->setScaledContents(true);
        Check_2 = new QPushButton(centralWidget);
        Check_2->setObjectName(QStringLiteral("Check_2"));
        Check_2->setGeometry(QRect(867, 435, 111, 41));
        Check_2->setStyleSheet(QLatin1String("QPushButton {\n"
"background: rgb(238, 39, 39);\n"
"color: white;\n"
"border: 5px rgb(196, 32, 38);\n"
"border-radius: 5px;\n"
"} \n"
"\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background: rgb(255, 80, 80);\n"
"}\n"
""));
        CPR_2 = new QPushButton(centralWidget);
        CPR_2->setObjectName(QStringLiteral("CPR_2"));
        CPR_2->setGeometry(QRect(189, 260, 31, 21));
        QFont font1;
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        CPR_2->setFont(font1);
        CPR_2->setStyleSheet(QLatin1String("QPushButton {\n"
"background: rgb(238, 39, 39);\n"
"color: white;\n"
"border: 5px rgb(196, 32, 38);\n"
"border-radius: 5px;\n"
"} \n"
"\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background: rgb(255, 80, 80);\n"
"}\n"
""));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 580, 151, 31));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_5->setFont(font2);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 560, 41, 17));
        QFont font3;
        font3.setPointSize(15);
        label_6->setFont(font3);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(800, 510, 111, 141));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/images/AED.png")));
        GameWindow->setCentralWidget(centralWidget);
        Call911->raise();
        CPR->raise();
        pushButton_6->raise();
        Patient->raise();
        Scenario->raise();
        HowTo->raise();
        pushButton_7->raise();
        Check->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        Check_2->raise();
        CPR_2->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
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
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "GameWindow", nullptr));
        Call911->setText(QApplication::translate("GameWindow", "Call 911", nullptr));
        CPR->setText(QApplication::translate("GameWindow", "Do CPR", nullptr));
        Scenario->setText(QApplication::translate("GameWindow", "Current Scenario", nullptr));
        HowTo->setText(QApplication::translate("GameWindow", "HOW TO", nullptr));
        Patient->setText(QApplication::translate("GameWindow", "There will be the picture of the patient here", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("GameWindow", "hi", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        Check->setText(QApplication::translate("GameWindow", "Check \n"
"Responsiveness", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        Check_2->setText(QApplication::translate("GameWindow", "Apply Pads", nullptr));
        CPR_2->setText(QApplication::translate("GameWindow", "-", nullptr));
        label_5->setText(QApplication::translate("GameWindow", "Time Remaining", nullptr));
        label_6->setText(QApplication::translate("GameWindow", "0:00", nullptr));
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
