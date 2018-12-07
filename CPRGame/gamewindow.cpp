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

    QObject::connect(model, &CPR_Model::cursorChange,
                     this, &GameWindow::setCursorToDefault);
ui->stackedWidget->setCurrentIndex(0);

    //  set selection region of the patient neck
    neckTopLeft = QPoint(445,188);
    neckBottomRight = QPoint(523,217);

     chestTopLeft = QPoint(590,469);
     chestBottomRight = QPoint(760,515);

     AED_Pad1_TopLeft = QPoint(383,262);
     AED_Pad1_BottomRight = QPoint(438,347);

     AED_Pad2_TopLeft = QPoint(505,350);
     AED_Pad2_BottomRight = QPoint(578,432);

    isCheckingPulseAndBreath = false;
    isDoingAEDPad1 = false;
    isDoingAEDPad2 = false;
    isDoingCompression = false;

    ui->stackedWidget->setCurrentIndex(0);

    setMouseTracking(true);

     loadPulse = QPixmap(":images/checkBreathAndPulse.png").scaled(64,64,Qt::KeepAspectRatio);
     loadHandUp = QPixmap(":images/hands_up.png").scaled(64,64,Qt::KeepAspectRatio).transformed(rotateImage.rotate(-90));
     loadHandDown = QPixmap(":images/hands_down.png").scaled(48,48,Qt::KeepAspectRatio).transformed(rotateImage);;
     cursorAEDPads = QPixmap(":images/single-pad.png").scaled(64,64,Qt::KeepAspectRatio);
     appliedAEDPads = QPixmap(":images/single-pad.png").scaled(512,512,Qt::KeepAspectRatio);

     overlayImage = appliedAEDPads;

     totalAppliedPads = 0;

     /*
        QPixmap overlayImage = appliedAEDPads;

       QPixmap base = *ui->patientImage->pixmap();
       QPainter  painter(&base);
       painter.drawPixmap(300,1000,overlayImage);

       ui->patientImage->setPixmap(base);
       */
}

GameWindow::~GameWindow()
{
    delete ui;
}


void GameWindow::mousePressEvent(QMouseEvent *event)
{

    //  if the currentState of the game is checkForPulse

    qDebug() << "x: " << QCursor::pos().x() << "y: " << QCursor::pos().y();

    if(isCheckingPulseAndBreath
            && (event->x() <= neckBottomRight.x() && event->x() >= neckTopLeft.x())
            && (event->y() <= neckBottomRight.y() && event->y() >= neckTopLeft.y()))
    {
        qDebug() << "You clicked on neck";

        emit action(gameState->CHECK_PULSE_AND_BREATHING);


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
        emit action(gameState->APPLY_PADS);


    }
}

void GameWindow::mouseMoveEvent(QMouseEvent *event)
{

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Mouse Position: " << QCursor::pos();


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
         emit action(gameState->GIVE_COMPRESSION);
    }
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

void GameWindow::on_callAction_clicked()
{
    emit action(gameState->CALL_FOR_911_AND_AED);
}

void GameWindow::on_cprAction_clicked()
{

    isDoingCompression = true;

    newCursorImage = QCursor(loadHandUp);
    setCursor(newCursorImage);

    qDebug() << "Compression signal sent";
}

void GameWindow::on_breathAction_clicked()
{
    emit action(gameState->GIVE_BREATH);
    setCursor(Qt::ArrowCursor);
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
  //  emit action(gameState->APPLY_PADS);

    newCursorImage = QCursor(cursorAEDPads);
    setCursor(newCursorImage);

    isDoingAEDPad1 = true;
    isDoingAEDPad2 = true;
}


void GameWindow::on_checkBreathAndPulseButton_clicked()
{
    //   change isCheckingPulseAndBreathing flag to true

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

void GameWindow::on_playAgainButton_released()

{
    ui->stackedWidget->setCurrentIndex(0);
}

void GameWindow::on_tryAgainButton_released()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void GameWindow::on_playAgainButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void GameWindow::on_tryAgainButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
