#include "gamewindow.h"
#include "welcomescreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow w;
    // w.show();

    // Temporary way for us to view the welcome screen.  TODO: Reorder this later.
    WelcomeScreen ws;
     ws.show();
    QObject::connect(&ws, SIGNAL(startButtonClicked()),
                     &w, SLOT(openWindow()));


    // End TODO


    return a.exec();
}
