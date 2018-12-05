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
    QObject::connect(ui->cprAction, &QPushButton::clicked,
                     this, &GameWindow::on_cprAction_clicked);

    QObject::connect(ui->breathAction, &QPushButton::clicked,
                     this, &GameWindow::on_breathAction_clicked);

    QObject::connect(ui->checkResponseAction, &QPushButton::clicked,
                     this, &GameWindow::on_checkResponseAction_clicked);

    QObject::connect(ui->applyPadsAction, &QPushButton::clicked,
                     this, &GameWindow::on_applyPadsAction_clicked);

    //QObject::connect(ui->checkBreathAndPulseButton, &QPushButton::clicked,
                     //this, &GameWindow::on_checkBreathAction_clicked);

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

    //  set selection region of the patient neck
    neckTopLeft = QPoint(444,264);
    neckBottomRight = QPoint(527,296);

     chestTopLeft = QPoint(383,357);
     chestBottomRight = QPoint(568,458);

     AED_Pad1_TopLeft = QPoint(381,383);
     AED_Pad1_BottomRight = QPoint(457,478);

     AED_Pad2_TopLeft = QPoint(523,454);
     AED_Pad2_BottomRight = QPoint(595,510);

    isCheckingPulseAndBreath = false;
    isDoingAED = false;
    isDoingCompression = false;

    ui->stackedWidget->setCurrentIndex(0);

}

GameWindow::~GameWindow()
{
    delete ui;
}


void GameWindow::mousePressEvent(QMouseEvent *event)
{

    //  if the currentState of the game is checkForPulse

    qDebug() << "x: " << event->x() << "y: " << event->y();

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

}

void GameWindow::mouseReleaseEvent(QMouseEvent *event)
{

}

void GameWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "x: " << event->x() << "y: " << event->y();
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{

    if(isDoingCompression && event->key() == Qt::Key_Space){

        QPixmap currentPix = QPixmap(":images/hands_down.png").scaled(32,32,Qt::KeepAspectRatio);
        QCursor cursorImage = QCursor(currentPix);
        setCursor(cursorImage);

    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(isDoingCompression && event->key() == Qt::Key_Space){

        QPixmap currentPix = QPixmap(":images/hands_up.png").scaled(32,32,Qt::KeepAspectRatio);
        QCursor cursorImage = QCursor(currentPix);
        setCursor(cursorImage);

    }
}

void GameWindow::on_callAction_clicked()
{
    emit action(gameState->CALL_FOR_911_AND_AED);
}

void GameWindow::on_cprAction_clicked()
{
    emit action(gameState->GIVE_COMPRESSION);

    isDoingCompression = true;
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
}

void GameWindow::on_applyPadsAction_clicked()
{
    emit action(gameState->APPLY_PADS);
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
    QPixmap currentPix = QPixmap(":images/checkBreathAndPulse.png").scaled(32,32,Qt::KeepAspectRatio);
    QCursor cursorImage = QCursor(currentPix);
    setCursor(cursorImage);


}

void GameWindow::SetStatusBox(string status)
{
    ui->scenarioText->setText("Current Scenario: " + QString::fromStdString(status));
}

void GameWindow::SetTutorialBox(string message)
{
    ui->hintText->setText("\nHint: " + QString::fromStdString(message));
}


