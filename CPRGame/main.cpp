#include "gamewindow.h"
#include "welcomescreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	CPR_Model *m = new CPR_Model();
    GameWindow w(nullptr, m);
   
  

    // Temporary way for us to view the welcome screen.  TODO: Reorder this later.
    WelcomeScreen ws;
     ws.show();
    QObject::connect(&ws, SIGNAL(startButtonClicked()),
                     &w, SLOT(openWindow()));


    return a.exec();
}
