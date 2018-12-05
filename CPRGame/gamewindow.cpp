#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QDebug>
GameWindow::GameWindow(QWidget *parent, CPR_Model *model) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    gameState = new GameState();

    // listens from the view
    /*
    QObject::connect(ui->cprAction, &QPushButton::clicked,
                     //this, &GameWindow::on_cprAction_clicked);

    QObject::connect(ui->breathAction, &QPushButton::clicked,
                     this, &GameWindow::on_breathAction_clicked);

    QObject::connect(ui->checkResponseAction, &QPushButton::clicked,
                     this, &GameWindow::on_checkResponseAction_clicked);

    QObject::connect(ui->applyPadsAction, &QPushButton::clicked,
                     this, &GameWindow::on_applyPadsAction_clicked);
    QObject::connect(ui->checkBreathAction, &QPushButton::clicked,
                     this, &GameWindow::on_checkBreathAction_clicked);
                     */

    // talks to the model
    QObject::connect(this, &GameWindow::action,
                     model, &CPR_Model::actionPerformed);
    QObject::connect(ui->normalPlayButton, &QPushButton::clicked,
                     model, &CPR_Model::newGame);
    QObject::connect(ui->normalPlayButton, &QPushButton::clicked,
                     [=]() {ui->stackedWidget->setCurrentIndex(1);});


    // Listens from the model
    QObject::connect(model, &CPR_Model::changeStatusBoxSignal,
                     this, &GameWindow::SetStatusBox);

    QObject::connect(model, &CPR_Model::changeTutorialBoxSignal,
                     this, &GameWindow::SetTutorialBox);


    ui->stackedWidget->setCurrentIndex(0);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_callAction_clicked()
{
    emit action(gameState->CALL_FOR_911_AND_AED);
}

void GameWindow::on_cprAction_clicked()
{
    emit action(gameState->GIVE_COMPRESSION);
    qDebug() << "Compression signal sent";
}

void GameWindow::on_breathAction_clicked()
{
    emit action(gameState->GIVE_BREATH);
}

void GameWindow::on_checkResponseAction_clicked()
{
    emit action(gameState->CHECK_RESPONSIVENESS);
}

void GameWindow::on_checkBreathAction_clicked()
{
    emit action(gameState->CHECK_PULSE_AND_BREATHING);
    qDebug() << "Breath signal sent";
}

void GameWindow::on_applyPadsAction_clicked()
{
    emit action(gameState->APPLY_PADS);
}

void GameWindow::SetStatusBox(string status)
{
    ui->scenarioText->setText("Current Scenario: " + QString::fromStdString(status));
}

void GameWindow::SetTutorialBox(string message)
{
    ui->hintText->setText("\nHint: " + QString::fromStdString(message));
}
