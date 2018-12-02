#include "gamewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CPR_Model *m = new CPR_Model();
    GameWindow w(nullptr, m);
    w.show();

    return a.exec();
}
