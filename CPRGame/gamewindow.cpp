/**
 * This is the GameWindow class. This class displays the appropriate GUI for the CPR
 * Game.
 */
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QDebug>

/**
 * The GameWindow constructor initializes the GUI and adds connections between the model
 * and GUI.
 */
GameWindow::GameWindow(QWidget *parent, CPR_Model *model) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    gameState = new GameState();

    // Sound players for the correct and incorrect sound
    correctSound = new QMediaPlayer;
    incorrectSound = new QMediaPlayer;

    correctSound->setMedia(QUrl("qrc:/sounds/Correct.mp3"));
    correctSound->setVolume(75);

    incorrectSound->setMedia(QUrl("qrc:/sounds/Nope.mp3"));
    incorrectSound->setVolume(75);

    // Set the current page to the title screen.
    ui->stackedWidget->setCurrentIndex(0);

    gameState = new GameState();

    // Talks to the model by giving actions and how to setup our game.
    QObject::connect(this, &GameWindow::action,
                     model, &CPR_Model::actionPerformed);
    QObject::connect(ui->normalPlayButton, &QPushButton::clicked,
                     model, &CPR_Model::newGame);

    // If the user selects normal mode, set the current page to the Game Window.
    QObject::connect(ui->normalPlayButton, &QPushButton::clicked,
                     [=]() {ui->stackedWidget->setCurrentIndex(1);});

    // Listens from the model of what messages to display in the
    // tutorial and hint box. Also listens to the state of the AED.
    QObject::connect(model, &CPR_Model::changeStatusBoxSignal,
                     this, &GameWindow::SetStatusBox);
    QObject::connect(model, &CPR_Model::changeTutorialBoxSignal,
                     this, &GameWindow::SetTutorialBox);
    QObject::connect(model, &CPR_Model::toggleAEDSignal,
                     this, &GameWindow::toggleAEDSlot);
    QObject::connect(model, &CPR_Model::isMoveCorrect,
                     this, &GameWindow::setMoveFeedback);
}

/**
  * The GameWindow destructor deletes the UI from memory when the program terminates.
  */
GameWindow::~GameWindow()
{
    delete ui;
    delete correctSound;
    delete incorrectSound;
}

/**
 *  Enables and disables buttons given an AED status.
 */
void GameWindow::toggleAEDSlot(bool toggle)
{
    // Handles the current state of the AED buttons given an AED status.
    ui->AEDPowerButton->setEnabled(toggle);
    ui->padsButton->setEnabled(toggle);
    ui->aedIcon->setEnabled(toggle);
    ui->shockButton->setEnabled(toggle);
    ui->shoutClear->setEnabled(toggle);

    // Sets the AED Status message given the AED status from the model.
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
        correctSound->play();
        ui->patientImage->setStyleSheet("border: 3px solid green;");
    }
    else
    {
        incorrectSound->play();
        ui->patientImage->setStyleSheet("border: 3px solid red;");
    }

    QTimer::singleShot(1000, this,
                       [=]() {ui->patientImage->setStyleSheet("border: 3px solid white;");});

}

/**
 * Handles the call 911 action.
 */
void GameWindow::on_callAction_clicked()
{
    emit action(gameState->CALL_FOR_911_AND_AED);
}

/**
 * Handles the give compression action.
 */
void GameWindow::on_cprAction_clicked()
{
    emit action(gameState->GIVE_COMPRESSION);
    qDebug() << "Compression signal sent";
}

/**
 * Handles the give breaths action.
 */
void GameWindow::on_breathAction_clicked()
{
    emit action(gameState->GIVE_BREATH);
}

/**
 * Handles the check for response action.
 */
void GameWindow::on_checkResponseAction_clicked()
{
    emit action(gameState->CHECK_RESPONSIVENESS);
}

/**
 * Handles the check for response action.
 */
void GameWindow::on_checkBreathAction_clicked()
{
    emit action(gameState->CHECK_PULSE_AND_BREATHING);
    qDebug() << "Breath signal sent";
}

/**
 * Handles what is displayed in the scenario box.
 */
void GameWindow::SetStatusBox(string status)
{
    ui->scenarioText->setText(QString::fromStdString(status));
}

/**
 * Handles what is displayed in the hint box.
 */
void GameWindow::SetTutorialBox(string message)
{
    ui->hintText->setText(QString::fromStdString(message));
}

/**
 * Handles the action when the AED is powered on.
 */
void GameWindow::on_AEDPowerButton_clicked()
{
    emit action(gameState->TURN_ON_AED);
}

/**
 * Handles the action when the "CLEAR" action is pressed.
 */
void GameWindow::on_shoutClear_clicked()
{
    emit action(gameState->SHOUT_CLEAR);
}

/**
 *  Handles the action when the pads button is pressed.
 */
void GameWindow::on_padsButton_clicked()
{
    emit action(gameState->APPLY_PADS);
}

/**
 * Handles the action when the shock button is pressed.
 */
void GameWindow::on_shockButton_clicked()
{
    emit action(gameState->PRESS_SHOCK);
}
