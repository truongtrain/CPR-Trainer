#include "cpr_model.h"
#include "ui_cpr_model.h"

CPR_Model::CPR_Model(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CPR_Model)
{
    ui->setupUi(this);
}

CPR_Model::~CPR_Model()
{
    delete ui;
}
