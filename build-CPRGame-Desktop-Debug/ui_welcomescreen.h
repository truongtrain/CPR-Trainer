/********************************************************************************
** Form generated from reading UI file 'welcomescreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMESCREEN_H
#define UI_WELCOMESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeScreen
{
public:
    QWidget *centralwidget;
    QLabel *animationLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WelcomeScreen)
    {
        if (WelcomeScreen->objectName().isEmpty())
            WelcomeScreen->setObjectName(QStringLiteral("WelcomeScreen"));
        WelcomeScreen->resize(800, 600);
        centralwidget = new QWidget(WelcomeScreen);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        animationLabel = new QLabel(centralwidget);
        animationLabel->setObjectName(QStringLiteral("animationLabel"));
        animationLabel->setEnabled(true);
        animationLabel->setGeometry(QRect(0, 0, 421, 321));
        animationLabel->setCursor(QCursor(Qt::ArrowCursor));
        animationLabel->setAutoFillBackground(false);
        WelcomeScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WelcomeScreen);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        WelcomeScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(WelcomeScreen);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        WelcomeScreen->setStatusBar(statusbar);

        retranslateUi(WelcomeScreen);

        QMetaObject::connectSlotsByName(WelcomeScreen);
    } // setupUi

    void retranslateUi(QMainWindow *WelcomeScreen)
    {
        WelcomeScreen->setWindowTitle(QApplication::translate("WelcomeScreen", "MainWindow", Q_NULLPTR));
        animationLabel->setText(QApplication::translate("WelcomeScreen", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WelcomeScreen: public Ui_WelcomeScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMESCREEN_H
