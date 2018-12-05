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

private slots:
    void on_callAction_clicked();
    void on_cprAction_clicked();
    void on_breathAction_clicked();
    void on_checkResponseAction_clicked();
    void on_checkBreathAction_clicked();
    void SetStatusBox(string s);
    void SetTutorialBox(string s);
    void toggleAEDSlot(bool toggle);

    void on_AEDPowerButton_clicked();

    void on_pushButton_6_clicked();

    void on_shoutClear_clicked();

    void on_padsButton_clicked();

signals:
    void action(int state);
};
#endif // GAMEWINDOW_H
