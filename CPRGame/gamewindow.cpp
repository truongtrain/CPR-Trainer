#include "gamewindow.h"
#include "ui_gamewindow.h"
GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
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
