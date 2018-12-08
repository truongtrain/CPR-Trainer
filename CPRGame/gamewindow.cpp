/**
 * This is the GameWindow class. This class displays the appropriate GUI for the CPR
 * Game.
 */
#include "gamewindow.h"
#include "ui_gamewindow.h"

/**
 * The GameWindow constructor initializes the GUI and adds connections between the model
 * and GUI.
 */
GameWindow::GameWindow(QWidget *parent, CPR_Model *model) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    // Sound players for the correct and incorrect sound
    correctSound = new QMediaPlayer;
    incorrectSound = new QMediaPlayer;
    winSound = new QMediaPlayer;
    loseSound = new QMediaPlayer;

    correctSound->setMedia(QUrl("qrc:/sounds/Correct.mp3"));
    correctSound->setVolume(75);

    incorrectSound->setMedia(QUrl("qrc:/sounds/Nope.mp3"));
    incorrectSound->setVolume(75);

    winSound->setMedia(QUrl("qrc:/sounds/sweetVictory.mp3"));
    winSound->setVolume(100);

    loseSound->setMedia(QUrl("qrc:/sounds/Violin.mp3"));
    loseSound->setVolume(100);


    // Set the current page to the title screen.
    ui->stackedWidget->setCurrentIndex(0);

    //  set selection region of the patient neck
    neckTopLeft = QPoint(400,150);
    neckBottomRight = QPoint(550,230);

    chestTopLeft = QPoint(517,475);
    chestBottomRight = QPoint(698,600);

    AED_Pad1_TopLeft = QPoint(383,262);
    AED_Pad1_BottomRight = QPoint(438,347);

    AED_Pad2_TopLeft = QPoint(505,350);
    AED_Pad2_BottomRight = QPoint(578,432);

    isCheckingPulseAndBreath = false;
    isDoingAEDPad1 = false;
    isDoingAEDPad2 = false;
    isDoingCompression = false;

    setMouseTracking(true);

    loadPulse = QPixmap(":images/checkBreathAndPulse.png").scaled(64,64,Qt::KeepAspectRatio);
    loadHandUp = QPixmap(":images/hands_up.png").scaled(64,64,Qt::KeepAspectRatio).transformed(rotateImage.rotate(-90));
    loadHandDown = QPixmap(":images/hands_down.png").scaled(48,48,Qt::KeepAspectRatio).transformed(rotateImage);;
    cursorAEDPads = QPixmap(":images/single-pad.png").scaled(64,64,Qt::KeepAspectRatio);
    appliedAEDPads = QPixmap(":images/single-pad.png").scaled(512,512,Qt::KeepAspectRatio);

    overlayImage = appliedAEDPads;

    // Talks to the model by giving actions and how to setup our game.
    QObject::connect(this, &GameWindow::action,
                     model, &CPR_Model::actionPerformed);
    QObject::connect(this, &GameWindow::newGame,
                     model, &CPR_Model::newGame);

    // Hide the hint label and text if pro mode is enabled.  Show again if regular mode.
    QObject::connect(ui->proPlayButton, &QPushButton::clicked,
                     [=]() {this->ui->hintLabel->hide();});
    QObject::connect(ui->proPlayButton, &QPushButton::clicked,
                     [=]() {this->ui->hintText->hide();});
    QObject::connect(ui->normalPlayButton, &QPushButton::clicked,
                     [=]() {this->ui->hintLabel->show();});
    QObject::connect(ui->normalPlayButton, &QPushButton::clicked,
                     [=]() {this->ui->hintText->show();});


    // If the user selects normal mode, set the current page to the Game Window.
    QObject::connect(ui->normalPlayButton, &QPushButton::clicked,
                     [=]() {ui->stackedWidget->setCurrentIndex(1);});
    QObject::connect(ui->proPlayButton, &QPushButton::clicked,
                     [=]() {ui->stackedWidget->setCurrentIndex(1);});

    // Listens from the model of what messages to display in the
    // tutorial and hint box. Also listens to the state of the AED.
    QObject::connect(model, &CPR_Model::changeStatusBoxSignal,
                     this, &GameWindow::setStatusBox);
    QObject::connect(model, &CPR_Model::changeTutorialBoxSignal,
                     this, &GameWindow::setTutorialBox);
    QObject::connect(model, &CPR_Model::toggleAEDSignal,
                     this, &GameWindow::toggleAEDSlot);
    QObject::connect(model, &CPR_Model::isMoveCorrect,
                     this, &GameWindow::setMoveFeedback);
    QObject::connect(model, &CPR_Model::cursorChange,
                     this, &GameWindow::setCursorToDefault);
    QObject::connect(model, &CPR_Model::gameOverLoseSignal,
                     this, &GameWindow::gameOverLose);
    QObject::connect(model, &CPR_Model::gameOverWinSignal,
                     this, &GameWindow::gameOverWin);
    QObject::connect(model, &CPR_Model::changeTimeLeftSignal,
                     this, &GameWindow::changeTimeLeftSlot);
    QObject::connect(model, &CPR_Model::updateLcdSignal,
                     this->ui->lcdNumber, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));

}

GameWindow::~GameWindow()
{
    delete ui;
    delete correctSound;
    delete incorrectSound;
    delete winSound;
    delete loseSound;
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    if(isCheckingPulseAndBreath
            && (event->x() <= neckBottomRight.x() && event->x() >= neckTopLeft.x())
            && (event->y() <= neckBottomRight.y() && event->y() >= neckTopLeft.y()))
    {

        emit action(CPR_Model::CHECK_PULSE_AND_BREATHING);
        setCursor(Qt::ArrowCursor);

        // reable the buttons
        ui->cprAction->setEnabled(true);
        ui->breathAction->setEnabled(true);
        ui->callAction->setEnabled(true);
        ui->checkResponseAction->setEnabled(true);

        isCheckingPulseAndBreath = false;

    }

    // this is for top left pad
    if(isDoingAEDPad1
            && (event->x() <= AED_Pad1_BottomRight.x() && event->x() >= AED_Pad1_TopLeft.x())
            && (event->y() <= AED_Pad1_BottomRight.y() && event->y() >= AED_Pad1_TopLeft.y()))
    {

       baseImage = *ui->patientImage->pixmap();
       QPainter painter(&baseImage);

       painter.drawPixmap(915,1600,overlayImage);
       ui->patientImage->setPixmap(baseImage);
       totalAppliedPads++;
       isDoingAEDPad1 = false;
    }

    // this is for bottom right pads
    if(isDoingAEDPad2
            && (event->x() <= AED_Pad2_BottomRight.x() && event->x() >= AED_Pad2_TopLeft.x())
            && (event->y() <= AED_Pad2_BottomRight.y() && event->y() >= AED_Pad2_TopLeft.y()))
    {

       baseImage = *ui->patientImage->pixmap();
       QPainter painter(&baseImage);

       painter.drawPixmap(1755,2400,overlayImage.transformed(rotateImage));
       ui->patientImage->setPixmap(baseImage);
       totalAppliedPads++;
       isDoingAEDPad2 = false;
    }

}

void GameWindow::mouseReleaseEvent(QMouseEvent *event)
{

    if(totalAppliedPads == 2)
    {
        emit action(CPR_Model::APPLY_PADS);
        totalAppliedPads = 0;

    }
}

void GameWindow::mouseMoveEvent(QMouseEvent *event)
{

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if(isDoingCompression && event->key() == Qt::Key_Space
            && (QCursor::pos().x() <= chestBottomRight.x() && QCursor::pos().x() >= chestTopLeft.x())
            && (QCursor::pos().y() <= chestBottomRight.y() && QCursor::pos().y() >= chestTopLeft.y())){


        newCursorImage = QCursor(loadHandDown);
        setCursor(newCursorImage);
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{


    if(isDoingCompression && event->key() == Qt::Key_Space
            && (QCursor::pos().x() <= chestBottomRight.x() && QCursor::pos().x() >= chestTopLeft.x())
            && (QCursor::pos().y() <= chestBottomRight.y() && QCursor::pos().y() >= chestTopLeft.y())){

        newCursorImage = QCursor(loadHandUp);
        setCursor(newCursorImage);

        //signal give compressions
         emit action(CPR_Model::GIVE_COMPRESSION);
    }
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
    setCursor(Qt::ArrowCursor);

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


void GameWindow::on_callAction_clicked()
{
    emit action(CPR_Model::CALL_FOR_911_AND_AED);
}


void GameWindow::on_cprAction_clicked()
{

    isDoingCompression = true;

    newCursorImage = QCursor(loadHandUp);
    setCursor(newCursorImage);
}


void GameWindow::on_breathAction_clicked()
{
    emit action(CPR_Model::GIVE_BREATH);
    setCursor(Qt::ArrowCursor);
}


void GameWindow::on_checkResponseAction_clicked()
{
    emit action(CPR_Model::CHECK_RESPONSIVENESS);
}

void GameWindow::openWindow()
{
    this->show();
}

void GameWindow::on_checkBreathAction_clicked()
{
    emit action(CPR_Model::CHECK_PULSE_AND_BREATHING);
}

void GameWindow::setStatusBox(string status)
{
    ui->scenarioText->setText(QString::fromStdString(status));
}


void GameWindow::setTutorialBox(string message)
{
    ui->hintText->setText(QString::fromStdString(message));
}

void GameWindow::on_AEDPowerButton_clicked()
{
    emit action(CPR_Model::TURN_ON_AED);

}

void GameWindow::on_shockButton_clicked()
{
    emit action(CPR_Model::PRESS_SHOCK);
}

void GameWindow::on_shoutClear_clicked()
{
    emit action(CPR_Model::SHOUT_CLEAR);
}


void GameWindow::on_padsButton_clicked()
{
    newCursorImage = QCursor(cursorAEDPads);
    setCursor(newCursorImage);

    isDoingAEDPad1 = true;
    isDoingAEDPad2 = true;
    totalAppliedPads = 0;
}


void GameWindow::on_checkBreathAndPulseButton_clicked()
{
    isCheckingPulseAndBreath = true;

    //  disable other buttons
    ui->cprAction->setEnabled(false);
    ui->breathAction->setEnabled(false);
    ui->callAction->setEnabled(false);

    //  change the cursor image to pulse checking finger
    newCursorImage = QCursor(loadPulse);
    setCursor(newCursorImage);

}

void GameWindow::setCursorToDefault()
{
    setCursor(Qt::ArrowCursor);
}


void GameWindow::on_playAgainButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->patientImage->setPixmap(*new QPixmap(":images/patient.jpg"));
    winSound->stop();
    loseSound->stop();
}

void GameWindow::on_tryAgainButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->patientImage->setPixmap(*new QPixmap(":images/patient.jpg"));
    winSound->stop();
    loseSound->stop();
}

void GameWindow::gameOverLose()
{
    setCursorToDefault();
    ui->stackedWidget->setCurrentIndex(3);
    loseSound->play();
}

void GameWindow::gameOverWin()
{
    setCursorToDefault();
    ui->stackedWidget->setCurrentIndex(2);
    winSound->play();
}

void GameWindow::changeTimeLeftSlot(int time)
{
    ui->timeRemaining->setText(QString::number(time));
}


void GameWindow::on_normalPlayButton_clicked()
{
    // Hide and show the appropriate labels for normal mode
    ui->hintText->show();
    ui->hintLabel->show();
    ui->timeLabel->hide();
    ui->timeRemaining->hide();
    emit newGame(false);
}

void GameWindow::on_proPlayButton_clicked()
{
    // Hide and show the appropriate labels for pro mode
    ui->hintText->hide();
    ui->hintLabel->hide();
    ui->timeLabel->show();
    ui->timeRemaining->show();
    emit newGame(true);
}
