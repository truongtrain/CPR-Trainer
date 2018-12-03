#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QBrush>
#include <QString>
#include "gamestate.h"
#include "cpr_model.h"
namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0, CPR_Model *model = new CPR_Model());
    ~GameWindow();
    GameState* gameState;

private:
    Ui::GameWindow *ui;


protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_minimize_released();
    void on_proOff_released();
    void on_proOn_released();

    void on_callAction_clicked();
    void on_cprAction_clicked();
    void on_breathAction_clicked();
    void on_checkResponseAction_clicked();
    void on_applyPadsAction_clicked();

    void SetStatusBox(string s);
    void SetTutorialBox(string s);

signals:
    void action(int state);
};
#endif // GAMEWINDOW_H
