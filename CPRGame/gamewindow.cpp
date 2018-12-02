#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QDebug>
GameWindow::GameWindow(QWidget *parent, cpr_mpodel model) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    gameState = gameState();

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
}

void GameWindow::on_proOn_released()
{
    ui->proOn->setChecked(true);
    ui->proOff->setChecked(false);
}

void GameWindow::on_callAction_clicked()
{
    emit action(gameState.CALL_FOR_911_AND_AED);
}

void GameWindow::on_cprAction_clicked()
{
    emit action(gameState.GIVE_COMPRESSION);
}

void GameWindow::on_breathAction_clicked()
{
    emit action(gameState.GIVE_BREATH);
}

void GameWindow::on_checkResponseAction_clicked()
{
    emit action(gameState.CHECK_RESPONSIVENESS);
}

void GameWindow::on_applyPadsAction_clicked()
{
    emit action(gameState.APPLY_PADS);
}
