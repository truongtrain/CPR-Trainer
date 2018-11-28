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
    QPushButton *callAction;
    QPushButton *cprAction;
    QLabel *scenarioText;
    QLabel *hintText;
    QLabel *patientImage;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *checkResponseAction;
    QLabel *callIcon;
    QLabel *cprIcon;
    QLabel *checkResponseIcon;
    QLabel *padsIcon;
    QPushButton *applyPadsAction;
    QPushButton *minimize;
    QLabel *timeLabel;
    QLabel *timeRemaining;
    QLabel *aedIcon;
    QLabel *aedLabel;
    QLabel *line;
    QLabel *aedStatus;
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
        callAction = new QPushButton(centralWidget);
        callAction->setObjectName(QStringLiteral("callAction"));
        callAction->setGeometry(QRect(850, 60, 121, 31));
        callAction->setStyleSheet(QLatin1String("QPushButton {\n"
"background: rgb(238, 39, 39);\n"
"color: white;\n"
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
        cprAction = new QPushButton(centralWidget);
        cprAction->setObjectName(QStringLiteral("cprAction"));
        cprAction->setGeometry(QRect(850, 140, 121, 31));
        cprAction->setStyleSheet(QLatin1String("QPushButton {\n"
"background: rgb(238, 39, 39);\n"
"color: white;\n"
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
        scenarioText = new QLabel(centralWidget);
        scenarioText->setObjectName(QStringLiteral("scenarioText"));
        scenarioText->setGeometry(QRect(30, 40, 200, 200));
        scenarioText->setAutoFillBackground(false);
        scenarioText->setStyleSheet(QLatin1String("color: white;\n"
"background: rgb(238, 39, 39);\n"
"border: 1px rgb(196, 32, 38);"));
        scenarioText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        hintText = new QLabel(centralWidget);
        hintText->setObjectName(QStringLiteral("hintText"));
        hintText->setEnabled(true);
        hintText->setGeometry(QRect(30, 269, 200, 191));
        hintText->setAutoFillBackground(false);
        hintText->setStyleSheet(QLatin1String("color: white;\n"
"background: rgb(238, 39, 39);\n"
"border: 1px rgb(196, 32, 38);"));
        hintText->setTextFormat(Qt::PlainText);
        hintText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        patientImage = new QLabel(centralWidget);
        patientImage->setObjectName(QStringLiteral("patientImage"));
        patientImage->setGeometry(QRect(270, 29, 450, 661));
        patientImage->setAutoFillBackground(true);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(770, 410, 51, 51));
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
        pushButton_7->setGeometry(QRect(770, 330, 51, 51));
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
        checkResponseAction = new QPushButton(centralWidget);
        checkResponseAction->setObjectName(QStringLiteral("checkResponseAction"));
        checkResponseAction->setGeometry(QRect(850, 220, 121, 51));
        checkResponseAction->setStyleSheet(QLatin1String("QPushButton {\n"
" border-radius: 5px;\n"
" background: rgb(238, 39, 39);\n"
" color: white;\n"
"} \n"
"\n"
"QPushButton:hover:!pressed {\n"
"  border: 1px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background: rgb(255, 80, 80);\n"
"}\n"
""));
        checkResponseAction->setCheckable(false);
        checkResponseAction->setChecked(false);
        checkResponseAction->setFlat(true);
        callIcon = new QLabel(centralWidget);
        callIcon->setObjectName(QStringLiteral("callIcon"));
        callIcon->setGeometry(QRect(770, 40, 71, 71));
        callIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/call.png")));
        cprIcon = new QLabel(centralWidget);
        cprIcon->setObjectName(QStringLiteral("cprIcon"));
        cprIcon->setGeometry(QRect(770, 120, 71, 81));
        cprIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/cpr.png")));
        checkResponseIcon = new QLabel(centralWidget);
        checkResponseIcon->setObjectName(QStringLiteral("checkResponseIcon"));
        checkResponseIcon->setGeometry(QRect(770, 210, 67, 71));
        checkResponseIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/check.png")));
        padsIcon = new QLabel(centralWidget);
        padsIcon->setObjectName(QStringLiteral("padsIcon"));
        padsIcon->setGeometry(QRect(760, 490, 84, 110));
        padsIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/pads.png")));
        padsIcon->setScaledContents(true);
        applyPadsAction = new QPushButton(centralWidget);
        applyPadsAction->setObjectName(QStringLiteral("applyPadsAction"));
        applyPadsAction->setGeometry(QRect(750, 610, 111, 41));
        applyPadsAction->setStyleSheet(QLatin1String("QPushButton {\n"
"background: rgb(238, 39, 39);\n"
"color: white;\n"
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
        minimize = new QPushButton(centralWidget);
        minimize->setObjectName(QStringLiteral("minimize"));
        minimize->setGeometry(QRect(30, 260, 201, 21));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(minimize->sizePolicy().hasHeightForWidth());
        minimize->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(37);
        font1.setBold(false);
        font1.setWeight(50);
        minimize->setFont(font1);
        minimize->setCursor(QCursor(Qt::ArrowCursor));
        minimize->setLayoutDirection(Qt::LeftToRight);
        minimize->setAutoFillBackground(false);
        minimize->setStyleSheet(QLatin1String("background: rgb(238, 39, 39);\n"
"color: white;\n"
"\n"
"\n"
"\n"
""));
        minimize->setFlat(false);
        timeLabel = new QLabel(centralWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(50, 580, 181, 31));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        timeLabel->setFont(font2);
        timeLabel->setStyleSheet(QLatin1String("color: white;\n"
""));
        timeRemaining = new QLabel(centralWidget);
        timeRemaining->setObjectName(QStringLiteral("timeRemaining"));
        timeRemaining->setGeometry(QRect(90, 536, 111, 41));
        QFont font3;
        font3.setPointSize(40);
        timeRemaining->setFont(font3);
        timeRemaining->setStyleSheet(QStringLiteral("color: white;"));
        aedIcon = new QLabel(centralWidget);
        aedIcon->setObjectName(QStringLiteral("aedIcon"));
        aedIcon->setGeometry(QRect(870, 330, 111, 141));
        aedIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/AED.png")));
        aedLabel = new QLabel(centralWidget);
        aedLabel->setObjectName(QStringLiteral("aedLabel"));
        aedLabel->setGeometry(QRect(870, 490, 111, 31));
        QFont font4;
        font4.setPointSize(14);
        font4.setUnderline(true);
        aedLabel->setFont(font4);
        aedLabel->setStyleSheet(QLatin1String("color: white;\n"
""));
        aedLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        line = new QLabel(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(760, 290, 221, 21));
        aedStatus = new QLabel(centralWidget);
        aedStatus->setObjectName(QStringLiteral("aedStatus"));
        aedStatus->setGeometry(QRect(870, 530, 111, 131));
        QFont font5;
        font5.setPointSize(12);
        aedStatus->setFont(font5);
        aedStatus->setStyleSheet(QLatin1String("color: white;\n"
""));
        aedStatus->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        GameWindow->setCentralWidget(centralWidget);
        callAction->raise();
        cprAction->raise();
        pushButton_6->raise();
        patientImage->raise();
        scenarioText->raise();
        hintText->raise();
        pushButton_7->raise();
        checkResponseAction->raise();
        callIcon->raise();
        cprIcon->raise();
        checkResponseIcon->raise();
        padsIcon->raise();
        applyPadsAction->raise();
        minimize->raise();
        timeLabel->raise();
        timeRemaining->raise();
        aedIcon->raise();
        aedLabel->raise();
        line->raise();
        aedStatus->raise();
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

        minimize->setDefault(false);


        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "GameWindow", nullptr));
        callAction->setText(QApplication::translate("GameWindow", "Call 911", nullptr));
        cprAction->setText(QApplication::translate("GameWindow", "Do CPR", nullptr));
        scenarioText->setText(QApplication::translate("GameWindow", "Current Scenario:", nullptr));
        hintText->setText(QApplication::translate("GameWindow", "\n"
"Hint: ", nullptr));
        patientImage->setText(QApplication::translate("GameWindow", "There will be the picture of the patient here", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("GameWindow", "hi", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        checkResponseAction->setText(QApplication::translate("GameWindow", "Check for\n"
" Response", nullptr));
        callIcon->setText(QString());
        cprIcon->setText(QString());
        checkResponseIcon->setText(QString());
        padsIcon->setText(QString());
        applyPadsAction->setText(QApplication::translate("GameWindow", "Apply Pads", nullptr));
        minimize->setText(QApplication::translate("GameWindow", "               -", nullptr));
        timeLabel->setText(QApplication::translate("GameWindow", "Time Remaining", nullptr));
        timeRemaining->setText(QApplication::translate("GameWindow", "0:00", nullptr));
        aedIcon->setText(QString());
        aedLabel->setText(QApplication::translate("GameWindow", "AED Status", nullptr));
        line->setText(QApplication::translate("GameWindow", "______________________________", nullptr));
        aedStatus->setText(QApplication::translate("GameWindow", "AED Arrived", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
