#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QBrush>
#include <QString>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDir>
#include "cpr_model.h"

namespace Ui {

/*
 * This is the GameWindow class. This class displays the appropriate GUI for the CPR
 * Game.
 */
class GameWindow;
}


class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*
     * initializes the GUI and adds connections between the model
     * and GUI.
     */
    explicit GameWindow(QWidget *parent = 0, CPR_Model *model = new CPR_Model());

    /**
      * The GameWindow destructor deletes the UI from memory when the program terminates.
      */
    ~GameWindow();

private:
    Ui::GameWindow *ui;
    QMediaPlayer *correctSound;
    QMediaPlayer *incorrectSound;
    QMediaPlayer *winSound;
    QMediaPlayer *loseSound;

    //  Selection region for neck
    QPoint neckTopLeft;
    QPoint neckBottomRight;

    QPoint chestTopLeft;
    QPoint chestBottomRight;
    QPoint AED_Pad1_TopLeft;
    QPoint AED_Pad1_BottomRight;
    QPoint AED_Pad2_TopLeft;
    QPoint AED_Pad2_BottomRight;

    bool isCheckingPulseAndBreath;
    bool isDoingCompression;
    bool isDoingAEDPad1;
    bool isDoingAEDPad2;

    QPixmap loadPulse;
    QPixmap loadHandUp;
    QPixmap loadHandDown;

    QPixmap cursorAEDPads;
    QPixmap appliedAEDPads;

    QPixmap overlayImage;
    QPixmap baseImage;

    int totalAppliedPads;

    QMatrix rotateImage;

    QCursor newCursorImage;


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

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
    void checkBreathAction_clicked();

    /**
     * Handles what is displayed in the scenario box.
     */
    void setStatusBox(string s);

    /**
     * Handles what is displayed in the hint box.
     */
    void setTutorialBox(string s);

    /**
     *  Enables and disables buttons given an AED status.
     */
    void toggleAEDSlot(bool toggle);

    /**
     * Gives feedback accordingly for if the move was correct or not
     */
    void setMoveFeedback(bool isCorrect);

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
     * Handles the action when the check pulse and breathing button is pressed.
     */
    void on_checkBreathAndPulseButton_clicked();

	/**
     * Handles the action when the shock button is pressed.
     */
    void on_shockButton_clicked();

    /**
     * Handles the action when players start a game in normal mode.
     */
    void on_normalPlayButton_clicked();

    /**
     * Handles the action when players start a game in pro mode.
     */
    void on_proPlayButton_clicked();

    /**
     * Sets the cursor back to the default pointer
     */
    void setCursorToDefault();


    /**
     * Resets the game from the win screen
     */
    void on_playAgainButton_clicked();

    /**
     * Resets the game from the lose screen
     */
    void on_tryAgainButton_clicked();

public slots:

    /**
     * Shows the window.
     */
    void openWindow();

    /**
     * Ends the game and brings the user to Lose screen.
     */
    void gameOverLose();

    /**
     * Ends the game and brings the user to Win screen.
     */
    void gameOverWin();

    /**
     * Displays the time remaining for the user to complete their next move
     */
    void changeTimeLeftSlot(int time);

signals:
    /**
     * A signal sent to the model with a given action
     */
    void action(int state);

    void newGame(bool isProMode);
};
#endif // GAMEWINDOW_H
