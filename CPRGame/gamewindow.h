#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QBrush>
#include <QString>
#include "gamestate.h"
#include "cpr_model.h"
namespace Ui {

/**
 * This is the GameWindow class. This class displays the appropriate GUI for the CPR
 * Game.
 */
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * The GameWindow constructor initializes the GUI and adds connections between the model
     * and GUI.
     */
    explicit GameWindow(QWidget *parent = 0, CPR_Model *model = new CPR_Model());

    /**
      * The GameWindow destructor deletes the UI from memory when the program terminates.
      */
    ~GameWindow();

    /**
     * Object that allows us to obtain the scenarios in our game.
     */
    GameState* gameState;

private:
    Ui::GameWindow *ui;

private slots:
    /**
     * Handles the call 911 action.
     */
    void on_callAction_clicked();

    /**
     * Handles the give compression action.
     */
    void on_cprAction_clicked();

    /**
     * Handles the give breaths action.
     */
    void on_breathAction_clicked();

    /**
     * Handles the check for response action.
     */
    void on_checkResponseAction_clicked();

    /**
     * Handles the check for response action.
     */
    void on_checkBreathAction_clicked();

    /**
     * Handles what is displayed in the scenario box.
     */
    void SetStatusBox(string s);

    /**
     * Handles what is displayed in the hint box.
     */
    void SetTutorialBox(string s);

    /**
     *  Enables and disables buttons given an AED status.
     */
    void toggleAEDSlot(bool toggle);

    /**
     * Handles the action when the AED is powered on.
     */
    void on_AEDPowerButton_clicked();

    /**
     * Handles the action when the "CLEAR" action is pressed.
     */
    void on_shoutClear_clicked();

    /**
     *  Handles the action when the pads button is pressed.
     */
    void on_padsButton_clicked();

    /**
     * Handles the action when the shock button is pressed.
     */
    void on_shockButton_clicked();

signals:
    /**
     * A signal sent to the model with a given action
     */
    void action(int state);
};
#endif // GAMEWINDOW_H
