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
#include <QtWidgets/QLCDNumber>
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
    QPushButton *breathAction;
    QLabel *breathIcon;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QPushButton *proOn;
    QPushButton *proOff;
    QLabel *label_2;
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
        callAction->setGeometry(QRect(860, 50, 121, 31));
        callAction->setFocusPolicy(Qt::NoFocus);
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
        callAction->setCheckable(false);
        cprAction = new QPushButton(centralWidget);
        cprAction->setObjectName(QStringLiteral("cprAction"));
        cprAction->setGeometry(QRect(853, 120, 134, 31));
        cprAction->setFocusPolicy(Qt::NoFocus);
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
        cprAction->setCheckable(false);
        scenarioText = new QLabel(centralWidget);
        scenarioText->setObjectName(QStringLiteral("scenarioText"));
        scenarioText->setGeometry(QRect(30, 40, 200, 200));
        scenarioText->setAutoFillBackground(false);
        scenarioText->setStyleSheet(QLatin1String("color: white;\n"
"background: rgb(238, 39, 39);\n"
"border: 1px rgb(196, 32, 38);"));
        scenarioText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scenarioText->setWordWrap(true);
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
        hintText->setWordWrap(true);
        hintText->setMargin(0);
        patientImage = new QLabel(centralWidget);
        patientImage->setObjectName(QStringLiteral("patientImage"));
        patientImage->setGeometry(QRect(270, 20, 450, 661));
        patientImage->setFocusPolicy(Qt::StrongFocus);
        patientImage->setAutoFillBackground(true);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(770, 440, 51, 51));
        pushButton_6->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_6->setFocusPolicy(Qt::NoFocus);
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
        pushButton_7->setGeometry(QRect(770, 360, 51, 51));
        pushButton_7->setFocusPolicy(Qt::NoFocus);
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
        checkResponseAction->setGeometry(QRect(860, 270, 121, 51));
        checkResponseAction->setFocusPolicy(Qt::NoFocus);
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
        callIcon->setGeometry(QRect(770, 30, 71, 71));
        callIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/call.png")));
        cprIcon = new QLabel(centralWidget);
        cprIcon->setObjectName(QStringLiteral("cprIcon"));
        cprIcon->setGeometry(QRect(770, 105, 64, 64));
        cprIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/cpr.png")));
        checkResponseIcon = new QLabel(centralWidget);
        checkResponseIcon->setObjectName(QStringLiteral("checkResponseIcon"));
        checkResponseIcon->setGeometry(QRect(770, 260, 67, 71));
        checkResponseIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/check.png")));
        padsIcon = new QLabel(centralWidget);
        padsIcon->setObjectName(QStringLiteral("padsIcon"));
        padsIcon->setGeometry(QRect(760, 520, 84, 110));
        padsIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/pads.png")));
        padsIcon->setScaledContents(true);
        applyPadsAction = new QPushButton(centralWidget);
        applyPadsAction->setObjectName(QStringLiteral("applyPadsAction"));
        applyPadsAction->setGeometry(QRect(746, 640, 111, 41));
        applyPadsAction->setFocusPolicy(Qt::NoFocus);
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
        minimize->setGeometry(QRect(30, 260, 200, 21));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(minimize->sizePolicy().hasHeightForWidth());
        minimize->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        minimize->setFont(font1);
        minimize->setCursor(QCursor(Qt::ArrowCursor));
        minimize->setLayoutDirection(Qt::LeftToRight);
        minimize->setAutoFillBackground(false);
        minimize->setStyleSheet(QLatin1String("background: rgb(238, 39, 39);\n"
"color: white;\n"
"text-align: right;\n"
"padding-right: 5px;\n"
"\n"
"\n"
"\n"
"\n"
""));
        minimize->setCheckable(false);
        minimize->setChecked(false);
        minimize->setAutoDefault(false);
        minimize->setFlat(false);
        timeLabel = new QLabel(centralWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(50, 544, 181, 31));
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
        timeRemaining->setGeometry(QRect(90, 500, 111, 41));
        QFont font3;
        font3.setPointSize(40);
        timeRemaining->setFont(font3);
        timeRemaining->setStyleSheet(QStringLiteral("color: white;"));
        aedIcon = new QLabel(centralWidget);
        aedIcon->setObjectName(QStringLiteral("aedIcon"));
        aedIcon->setGeometry(QRect(870, 400, 111, 141));
        aedIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/AED.png")));
        aedLabel = new QLabel(centralWidget);
        aedLabel->setObjectName(QStringLiteral("aedLabel"));
        aedLabel->setGeometry(QRect(870, 550, 111, 31));
        QFont font4;
        font4.setPointSize(14);
        font4.setUnderline(true);
        aedLabel->setFont(font4);
        aedLabel->setStyleSheet(QLatin1String("color: white;\n"
""));
        aedLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        line = new QLabel(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(760, 320, 221, 21));
        aedStatus = new QLabel(centralWidget);
        aedStatus->setObjectName(QStringLiteral("aedStatus"));
        aedStatus->setGeometry(QRect(870, 590, 111, 50));
        QFont font5;
        font5.setPointSize(12);
        aedStatus->setFont(font5);
        aedStatus->setStyleSheet(QLatin1String("color: white;\n"
""));
        aedStatus->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        breathAction = new QPushButton(centralWidget);
        breathAction->setObjectName(QStringLiteral("breathAction"));
        breathAction->setGeometry(QRect(860, 200, 121, 31));
        breathAction->setFocusPolicy(Qt::NoFocus);
        breathAction->setStyleSheet(QLatin1String("QPushButton {\n"
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
        breathAction->setCheckable(false);
        breathIcon = new QLabel(centralWidget);
        breathIcon->setObjectName(QStringLiteral("breathIcon"));
        breathIcon->setGeometry(QRect(770, 185, 64, 64));
        breathIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/breaths.png")));
        breathIcon->setScaledContents(true);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(280, 620, 51, 51));
        lcdNumber->setStyleSheet(QLatin1String("background: rgb(238, 39, 39);\n"
"color: white;"));
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setDigitCount(3);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("intValue", QVariant(0));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 620, 101, 51));
        label->setStyleSheet(QStringLiteral("color:white"));
        proOn = new QPushButton(centralWidget);
        proOn->setObjectName(QStringLiteral("proOn"));
        proOn->setGeometry(QRect(85, 650, 50, 25));
        proOn->setFocusPolicy(Qt::NoFocus);
        proOn->setStyleSheet(QLatin1String("QPushButton {\n"
"background: rgb(238, 39, 39);\n"
"color: white;\n"
"border-style: flat;\n"
"} \n"
"\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid white;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"background: rgb(255, 80, 80);\n"
"}\n"
""));
        proOn->setCheckable(true);
        proOn->setChecked(false);
        proOff = new QPushButton(centralWidget);
        proOff->setObjectName(QStringLiteral("proOff"));
        proOff->setEnabled(true);
        proOff->setGeometry(QRect(135, 650, 50, 25));
        proOff->setFocusPolicy(Qt::NoFocus);
        proOff->setStyleSheet(QLatin1String("QPushButton {\n"
"background: rgb(238, 39, 39);\n"
"color: white;\n"
"border-style: flat;\n"
"} \n"
"\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid white;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"background: rgb(255, 80, 80);\n"
"}\n"
""));
        proOff->setCheckable(true);
        proOff->setChecked(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 615, 211, 31));
        QFont font6;
        font6.setPointSize(20);
        label_2->setFont(font6);
        label_2->setStyleSheet(QStringLiteral("color:white"));
        label_2->setTextFormat(Qt::RichText);
        label_2->setAlignment(Qt::AlignCenter);
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
        breathAction->raise();
        breathIcon->raise();
        lcdNumber->raise();
        label->raise();
        proOn->raise();
        proOff->raise();
        label_2->raise();
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
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "GameWindow", Q_NULLPTR));
        callAction->setText(QApplication::translate("GameWindow", "Call 911", Q_NULLPTR));
        cprAction->setText(QApplication::translate("GameWindow", "Do Compressions", Q_NULLPTR));
        scenarioText->setText(QApplication::translate("GameWindow", "Current Scenario:", Q_NULLPTR));
        hintText->setText(QApplication::translate("GameWindow", "\n"
"Hint: ", Q_NULLPTR));
        patientImage->setText(QApplication::translate("GameWindow", "There will be the picture of the patient here", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("GameWindow", "hi", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        checkResponseAction->setText(QApplication::translate("GameWindow", "Check for\n"
" Response", Q_NULLPTR));
        callIcon->setText(QString());
        cprIcon->setText(QString());
        checkResponseIcon->setText(QString());
        padsIcon->setText(QString());
        applyPadsAction->setText(QApplication::translate("GameWindow", "Apply Pads", Q_NULLPTR));
        minimize->setText(QApplication::translate("GameWindow", "-", Q_NULLPTR));
        timeLabel->setText(QApplication::translate("GameWindow", "Time Remaining", Q_NULLPTR));
        timeRemaining->setText(QApplication::translate("GameWindow", "0:00", Q_NULLPTR));
        aedIcon->setText(QString());
        aedLabel->setText(QApplication::translate("GameWindow", "AED Status", Q_NULLPTR));
        line->setText(QApplication::translate("GameWindow", "______________________________", Q_NULLPTR));
        aedStatus->setText(QApplication::translate("GameWindow", "AED Arrived", Q_NULLPTR));
        breathAction->setText(QApplication::translate("GameWindow", "Give Breaths", Q_NULLPTR));
        breathIcon->setText(QString());
        label->setText(QApplication::translate("GameWindow", "Compressions\n"
"Per\n"
"Minute", Q_NULLPTR));
        proOn->setText(QApplication::translate("GameWindow", "On", Q_NULLPTR));
        proOff->setText(QApplication::translate("GameWindow", "Off", Q_NULLPTR));
        label_2->setText(QApplication::translate("GameWindow", "Pro Mode", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
