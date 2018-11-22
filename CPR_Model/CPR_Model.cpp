#include "CPR_Model.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}




MainWindow::~MainWindow()
{
    delete ui;
}

//  cprRulesState will listen to the action given by user
//   and that action will set off the model's response
void MainWindow::cprRulesState(int)
{

}
