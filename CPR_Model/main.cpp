#include "cpr_model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CPR_Model w;
    w.show();

    return a.exec();
}
