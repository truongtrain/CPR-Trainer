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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *titlePage;
    QLabel *title;
    QPushButton *normalPlayButton;
    QPushButton *proPlayButton;
    QLabel *credits;
    QWidget *playPage;
    QLabel *label;
    QLabel *cprIcon;
    QPushButton *breathAction;
    QLabel *checkResponseIcon;
    QLabel *callIcon;
    QLabel *hintText;
    QLabel *line;
    QLabel *aedIcon;
    QLabel *aedLabel;
    QPushButton *applyPadsAction;
    QLabel *scenarioText;
    QPushButton *checkResponseAction;
    QLabel *aedStatus;
    QLCDNumber *lcdNumber;
    QLabel *timeLabel;
    QLabel *breathIcon;
    QPushButton *cprAction;
    QPushButton *pushButton_7;
    QLabel *padsIcon;
    QPushButton *callAction;
    QPushButton *pushButton_6;
    QLabel *timeRemaining;
    QLabel *patientImage;
    QLabel *playBackground;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QStringLiteral("GameWindow"));
        GameWindow->resize(1036, 740);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameWindow->sizePolicy().hasHeightForWidth());
        GameWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        GameWindow->setFont(font);
        GameWindow->setIconSize(QSize(84, 110));
        centralWidget = new QWidget(GameWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1041, 720));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(25,170,229);"));
        titlePage = new QWidget();
        titlePage->setObjectName(QStringLiteral("titlePage"));
        title = new QLabel(titlePage);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(240, 30, 501, 261));
        QFont font1;
        font1.setPointSize(66);
        title->setFont(font1);
        title->setPixmap(QPixmap(QString::fromUtf8(":/images/title.png")));
        title->setScaledContents(true);
        normalPlayButton = new QPushButton(titlePage);
        normalPlayButton->setObjectName(QStringLiteral("normalPlayButton"));
        normalPlayButton->setGeometry(QRect(240, 370, 211, 91));
        QFont font2;
        font2.setPointSize(22);
        normalPlayButton->setFont(font2);
        normalPlayButton->setStyleSheet(QLatin1String("QPushButton {\n"
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
        proPlayButton = new QPushButton(titlePage);
        proPlayButton->setObjectName(QStringLiteral("proPlayButton"));
        proPlayButton->setGeometry(QRect(550, 370, 211, 91));
        proPlayButton->setFont(font2);
        proPlayButton->setStyleSheet(QLatin1String("QPushButton {\n"
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
        credits = new QLabel(titlePage);
        credits->setObjectName(QStringLiteral("credits"));
        credits->setGeometry(QRect(300, 580, 381, 91));
        credits->setStyleSheet(QLatin1String("color: white;\n"
""));
        credits->setAlignment(Qt::AlignCenter);
        credits->setWordWrap(true);
        stackedWidget->addWidget(titlePage);
        playPage = new QWidget();
        playPage->setObjectName(QStringLiteral("playPage"));
        label = new QLabel(playPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(335, 620, 101, 51));
        label->setStyleSheet(QLatin1String("color:white;\n"
"background: transparent;"));
        cprIcon = new QLabel(playPage);
        cprIcon->setObjectName(QStringLiteral("cprIcon"));
        cprIcon->setGeometry(QRect(770, 105, 64, 64));
        cprIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/cpr.png")));
        breathAction = new QPushButton(playPage);
        breathAction->setObjectName(QStringLiteral("breathAction"));
        breathAction->setGeometry(QRect(860, 200, 121, 31));
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
        checkResponseIcon = new QLabel(playPage);
        checkResponseIcon->setObjectName(QStringLiteral("checkResponseIcon"));
        checkResponseIcon->setGeometry(QRect(770, 260, 64, 64));
        checkResponseIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/check.png")));
        callIcon = new QLabel(playPage);
        callIcon->setObjectName(QStringLiteral("callIcon"));
        callIcon->setGeometry(QRect(770, 30, 71, 71));
        callIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/call.png")));
        hintText = new QLabel(playPage);
        hintText->setObjectName(QStringLiteral("hintText"));
        hintText->setEnabled(true);
        hintText->setGeometry(QRect(30, 269, 200, 191));
        hintText->setAutoFillBackground(false);
        hintText->setStyleSheet(QLatin1String("color: white;\n"
"background: rgb(238, 39, 39);\n"
"padding: 3px;"));
        hintText->setTextFormat(Qt::PlainText);
        hintText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        hintText->setWordWrap(true);
        line = new QLabel(playPage);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(760, 330, 221, 21));
        aedIcon = new QLabel(playPage);
        aedIcon->setObjectName(QStringLiteral("aedIcon"));
        aedIcon->setGeometry(QRect(870, 400, 111, 141));
        aedIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/AED.png")));
        aedLabel = new QLabel(playPage);
        aedLabel->setObjectName(QStringLiteral("aedLabel"));
        aedLabel->setGeometry(QRect(870, 550, 111, 31));
        QFont font3;
        font3.setPointSize(14);
        font3.setUnderline(true);
        aedLabel->setFont(font3);
        aedLabel->setStyleSheet(QLatin1String("color: white;\n"
""));
        aedLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        applyPadsAction = new QPushButton(playPage);
        applyPadsAction->setObjectName(QStringLiteral("applyPadsAction"));
        applyPadsAction->setGeometry(QRect(746, 640, 111, 41));
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
        scenarioText = new QLabel(playPage);
        scenarioText->setObjectName(QStringLiteral("scenarioText"));
        scenarioText->setGeometry(QRect(30, 40, 200, 200));
        scenarioText->setAutoFillBackground(false);
        scenarioText->setStyleSheet(QLatin1String("color: white;\n"
"background: rgb(238, 39, 39);\n"
"padding: 3px;"));
        scenarioText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scenarioText->setWordWrap(true);
        checkResponseAction = new QPushButton(playPage);
        checkResponseAction->setObjectName(QStringLiteral("checkResponseAction"));
        checkResponseAction->setGeometry(QRect(860, 270, 121, 51));
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
        aedStatus = new QLabel(playPage);
        aedStatus->setObjectName(QStringLiteral("aedStatus"));
        aedStatus->setGeometry(QRect(870, 590, 111, 50));
        QFont font4;
        font4.setPointSize(12);
        aedStatus->setFont(font4);
        aedStatus->setStyleSheet(QLatin1String("color: white;\n"
""));
        aedStatus->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        lcdNumber = new QLCDNumber(playPage);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(275, 620, 51, 51));
        lcdNumber->setStyleSheet(QLatin1String("background: rgb(238, 39, 39);\n"
"color: white;"));
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setDigitCount(3);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("intValue", QVariant(0));
        timeLabel = new QLabel(playPage);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(40, 590, 181, 31));
        QFont font5;
        font5.setPointSize(18);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        timeLabel->setFont(font5);
        timeLabel->setStyleSheet(QLatin1String("color: white;\n"
"background: transparent;"));
        breathIcon = new QLabel(playPage);
        breathIcon->setObjectName(QStringLiteral("breathIcon"));
        breathIcon->setGeometry(QRect(770, 185, 64, 64));
        breathIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/breaths.png")));
        breathIcon->setScaledContents(true);
        cprAction = new QPushButton(playPage);
        cprAction->setObjectName(QStringLiteral("cprAction"));
        cprAction->setGeometry(QRect(853, 120, 134, 31));
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
        pushButton_7 = new QPushButton(playPage);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(770, 360, 51, 51));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid white;\n"
"}\n"
"\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/on.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon);
        pushButton_7->setIconSize(QSize(72, 72));
        pushButton_7->setFlat(true);
        padsIcon = new QLabel(playPage);
        padsIcon->setObjectName(QStringLiteral("padsIcon"));
        padsIcon->setGeometry(QRect(760, 520, 84, 110));
        padsIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/pads.png")));
        padsIcon->setScaledContents(true);
        callAction = new QPushButton(playPage);
        callAction->setObjectName(QStringLiteral("callAction"));
        callAction->setGeometry(QRect(860, 50, 121, 31));
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
        callAction->setCheckable(true);
        callAction->setChecked(false);
        pushButton_6 = new QPushButton(playPage);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(770, 440, 51, 51));
        pushButton_6->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_6->setToolTipDuration(5000);
        pushButton_6->setStyleSheet(QLatin1String("QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid white;\n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/shock.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon1);
        pushButton_6->setIconSize(QSize(72, 72));
        pushButton_6->setFlat(true);
        timeRemaining = new QLabel(playPage);
        timeRemaining->setObjectName(QStringLiteral("timeRemaining"));
        timeRemaining->setGeometry(QRect(80, 546, 111, 41));
        QFont font6;
        font6.setPointSize(40);
        timeRemaining->setFont(font6);
        timeRemaining->setStyleSheet(QLatin1String("color: white;\n"
"background: transparent;"));
        patientImage = new QLabel(playPage);
        patientImage->setObjectName(QStringLiteral("patientImage"));
        patientImage->setGeometry(QRect(265, 25, 450, 661));
        patientImage->setAutoFillBackground(false);
        patientImage->setStyleSheet(QStringLiteral("background: transparent;"));
        playBackground = new QLabel(playPage);
        playBackground->setObjectName(QStringLiteral("playBackground"));
        playBackground->setGeometry(QRect(15, 15, 720, 690));
        playBackground->setStyleSheet(QStringLiteral("background: gray;"));
        stackedWidget->addWidget(playPage);
        playBackground->raise();
        patientImage->raise();
        label->raise();
        cprIcon->raise();
        breathAction->raise();
        checkResponseIcon->raise();
        callIcon->raise();
        hintText->raise();
        line->raise();
        aedIcon->raise();
        aedLabel->raise();
        applyPadsAction->raise();
        scenarioText->raise();
        checkResponseAction->raise();
        aedStatus->raise();
        lcdNumber->raise();
        timeLabel->raise();
        breathIcon->raise();
        cprAction->raise();
        pushButton_7->raise();
        padsIcon->raise();
        callAction->raise();
        pushButton_6->raise();
        timeRemaining->raise();
        GameWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GameWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1036, 22));
        GameWindow->setMenuBar(menuBar);

        retranslateUi(GameWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "GameWindow", nullptr));
        title->setText(QString());
        normalPlayButton->setText(QApplication::translate("GameWindow", "Normal Mode", nullptr));
        proPlayButton->setText(QApplication::translate("GameWindow", "Pro Mode", nullptr));
        credits->setText(QApplication::translate("GameWindow", "<html><head/><body><p>*Please note that this game is intended to demonstrate a typical scenario where CPR is needed. Please take a real CPR class before attempting to be hero.</p><p>Made by Git Rekt 3505</p><p><br/></p></body></html>", nullptr));
        label->setText(QApplication::translate("GameWindow", "Compressions\n"
"Per\n"
"Minute", nullptr));
        cprIcon->setText(QString());
        breathAction->setText(QApplication::translate("GameWindow", "Give Breaths", nullptr));
        checkResponseIcon->setText(QString());
        callIcon->setText(QString());
        hintText->setText(QApplication::translate("GameWindow", "Hint: ", nullptr));
        line->setText(QApplication::translate("GameWindow", "______________________________", nullptr));
        aedIcon->setText(QString());
        aedLabel->setText(QApplication::translate("GameWindow", "AED Status", nullptr));
        applyPadsAction->setText(QApplication::translate("GameWindow", "Apply Pads", nullptr));
        scenarioText->setText(QApplication::translate("GameWindow", "Current Scenario:", nullptr));
        checkResponseAction->setText(QApplication::translate("GameWindow", "Check for\n"
" Response", nullptr));
        aedStatus->setText(QApplication::translate("GameWindow", "AED Arrived", nullptr));
        timeLabel->setText(QApplication::translate("GameWindow", "Time Remaining", nullptr));
        breathIcon->setText(QString());
        cprAction->setText(QApplication::translate("GameWindow", "Do Compressions", nullptr));
        pushButton_7->setText(QString());
        padsIcon->setText(QString());
        callAction->setText(QApplication::translate("GameWindow", "Call 911", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("GameWindow", "hi", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_6->setText(QString());
        timeRemaining->setText(QApplication::translate("GameWindow", "0:00", nullptr));
        patientImage->setText(QApplication::translate("GameWindow", "There will be the picture of the patient here", nullptr));
        playBackground->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
