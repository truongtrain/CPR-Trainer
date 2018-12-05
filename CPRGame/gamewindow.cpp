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

    QObject::connect(model, &CPR_Model::toggleAEDSignal,
                     this, &GameWindow::toggleAEDSlot);

    QObject::connect(model, &CPR_Model::isMoveCorrect,
                     this, &GameWindow::setMoveFeedback);


    ui->stackedWidget->setCurrentIndex(0);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::toggleAEDSlot(bool toggle)
{
    ui->AEDPowerButton->setEnabled(toggle);
    ui->padsButton->setEnabled(toggle);
    ui->aedIcon->setEnabled(toggle);
    //ui->applyPadsAction->setEnabled(toggle);
    ui->pushButton_6->setEnabled(toggle);

    if(toggle)
    {
        ui->aedStatus->setText("ARRIVED");
    }

    else
    {
        ui->aedStatus->setText("ON THE WAY");
    }
}

void GameWindow::setMoveFeedback(bool isCorrect)
{
    // Set the patient border to red/green for a second depending
    // on if the move they just made was incorrect/correct
    if(isCorrect)
    {
        ui->patientImage->setStyleSheet("border: 3px solid green;");
    }
    else
    {
        ui->patientImage->setStyleSheet("border: 3px solid red;");
    }

    QTimer::singleShot(1000, this,
                       [=]() {ui->patientImage->setStyleSheet("border: 3px solid white;");});

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

void GameWindow::SetStatusBox(string status)
{
    ui->scenarioText->setText(QString::fromStdString(status));
}

void GameWindow::SetTutorialBox(string message)
{
    ui->hintText->setText(QString::fromStdString(message));
}

void GameWindow::on_AEDPowerButton_clicked()
{
    emit action(gameState->TURN_ON_AED);
}

void GameWindow::on_pushButton_6_clicked()
{
    emit action(gameState->PRESS_SHOCK);
}

void GameWindow::on_shoutClear_clicked()
{
    emit action(gameState->SHOUT_CLEAR);
}

void GameWindow::on_padsButton_clicked()
{
    emit action(gameState->APPLY_PADS);
}
