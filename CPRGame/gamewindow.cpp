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

    // talks to the model
    QObject::connect(this, &GameWindow::action,
                     model, &CPR_Model::actionPerformed);
    QObject::connect(ui->proOff, &QPushButton::clicked,
                     model, &CPR_Model::newGame);

    // Listens from the model
    QObject::connect(model, &CPR_Model::changeStatusBoxSignal,
                     this, &GameWindow::SetStatusBox);

    QObject::connect(model, &CPR_Model::changeTutorialBoxSignal,
                     this, &GameWindow::SetTutorialBox);

    //  testing changing the cursor
    QPixmap cursor_pixmap = QPixmap(":images/AED_LL_Pads.jpg");
    QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
    setCursor(cursor_default);

}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::paintEvent(QPaintEvent *)
{
    //blue background on the widget
    QPainter painter(this);
    QBrush brush(QColor(25,170,229));
    painter.fillRect(0,0,this->frameSize().width(),this->frameSize().height(),brush);

    //gray background
    QBrush brush2(Qt::gray);
    painter.fillRect(15,15,720,690,brush2);
}

// both the mouse events will take care of
// applying pad state
void GameWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Mouse is press";
    qDebug() << "x: " << event->x() << "y: " << event->y();
}

void GameWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Mouse is Release";
}

//  Both keyPress and KeyRelease will be use for giving compression
//  the state the user must be in giveCompression stat and use space bar
void GameWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key is pressed";


}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << "Key is release";
}


void GameWindow::on_minimize_released()
{
    bool isExpanded = ui->hintText->isVisible();
    ui->hintText->setVisible(!isExpanded);

    // Show '-' if we have minimized or '+' if we have expanded
    if(isExpanded)
    {
        ui->minimize->setText(QString("+"));
    }
    else
    {
        ui->minimize->setText(QString("-"));
    }
}


void GameWindow::on_proOff_released()
{
    ui->proOn->setChecked(false);
    ui->proOff->setChecked(true);


    //  setting the starting image
    QPixmap pix = *new QPixmap(":images/DummyFromAbove.png");
    ui->patientImage->setPixmap(pix.scaled(ui->patientImage->width(),ui->patientImage->height(),Qt::KeepAspectRatio));
}

void GameWindow::on_proOn_released()
{
    ui->proOn->setChecked(true);
    ui->proOff->setChecked(false);
}

void GameWindow::on_callAction_clicked()
{
    emit action(gameState->CALL_FOR_911_AND_AED);
}

void GameWindow::on_cprAction_clicked()
{
    emit action(gameState->GIVE_COMPRESSION);
}

void GameWindow::on_breathAction_clicked()
{
    emit action(gameState->GIVE_BREATH);
}

void GameWindow::on_checkResponseAction_clicked()
{
    emit action(gameState->CHECK_RESPONSIVENESS);
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
