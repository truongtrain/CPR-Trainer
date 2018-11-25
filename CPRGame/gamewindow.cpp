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
