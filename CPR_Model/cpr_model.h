#ifndef CPR_MODEL_H
#define CPR_MODEL_H

#include <QMainWindow>

namespace Ui {
class CPR_Model;
}

class CPR_Model : public QMainWindow
{
    Q_OBJECT

public:
    explicit CPR_Model(QWidget *parent = 0);
    ~CPR_Model();

private:
    Ui::CPR_Model *ui;
};

#endif // CPR_MODEL_H
