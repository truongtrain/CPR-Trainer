#ifndef CPR_MODEL_H
#define CPR_MODEL_H

#include <QObject>
#include <iostream>
#include <QTimer>
#include "metronome.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

using namespace std;

/**
 * This is the CPR model class. The model interprets the actions sent from the
 * GUI and sends a result back to the GUI. This class handles the current state
 * of the game.
 */
class CPR_Model : public QObject
{
    Q_OBJECT

public:
    /**
     * CPR constructor that simply initializes a few of our fields for the game.
     */
    CPR_Model();

    /**
     * Constant integers that keeps track of scenarios.
     */
    enum GameState {
    CHECK_RESPONSIVENESS  = 0,
    CALL_FOR_911_AND_AED = 1,
    CHECK_PULSE_AND_BREATHING = 2,
    GIVE_BREATH = 3,
    PLACE_HANDS = 4,
    GIVE_COMPRESSION = 5,
    TURN_ON_AED = 6,
    APPLY_PADS = 7,
    SHOUT_CLEAR_FOR_ANALYZE = 8,
    PRESS_ANALYZE = 9,
    SHOUT_CLEAR_FOR_SHOCK = 10,
    PRESS_SHOCK = 11,
    GAME_OVER = 12,
    SHOUT_CLEAR = 13};

private:
    /**
     * Keeps track of the current scenario in our game.
     */
    int currentState;

    QMediaPlayer *stayinAlive;

    /**
     * Boolean flags to help keep track if certain conditions have been met
     * in our game (consciousness, pulse, and breathing).
     */
    bool isPatientConscious;
    bool doesPatientHavePulse;
    bool isPatientBreathing;

    /**
     * Is true when user clicks Pro Mode in our title screen.
     */
    bool isProMode;

    /**
     * Keeps track of the number of compressions and breaths given.
     */
    int compressionsGiven;
    int badCompressionsRateCount;
    int breathsGiven;

    /**
     * Keeps track of the number of cycles completed of compressions and
     * breaths.
     */
    int cyclesCompleted;

    /**

     * This is used for pro mode. When the time runs out, you lose the game.
     */
    int timeLeft;
     /* Used when monitoring compressions rate.
     */
    Metronome metronome;


    /**
     * Advances the current scenario if an action from the GUI was correct.
     */
    void advanceSuccessfully();

    /**
     * If pro mode is on, ends the game if the user selects the wrong action
     * in a given scenario.
     */
    void actionFailed();

    /**
     * Calculates how much time is left and sends it to the GUI
     */
    void displayTimeLeft();

public slots:
    /**
     * This is a slot that listens to the CPR actions performed from the view,
     * and decides if they were correct.
     */
    void actionPerformed(int);

    /**
     * Initializes a new game for our CPR game.
     */
    void newGame(bool);

signals:
    /**
     * Emits a signal to the GUI of the current scenario of our game.
     */
    void changeStatusBoxSignal(string message);

    /**
     * Emits a signal to the GUI of a hint to display.
     */
    void changeTutorialBoxSignal(string message);

    /**
     * Emits a signal to the GUI that the user has won the game.
     */
    void gameOverWinSignal(string message);

    /**
     * Emits a signal to the GUI that the user has lost the game.
     */
    void gameOverLoseSignal(string message);

    /**
     * Emits a signal to the GUI to change the time left indicator
     */
    void changeTimeLeftSignal(int time);

    void cursorChange();

    void isMoveCorrect(bool isCorrect);

    /**
     * Emits a signal to the GUI when the AED is activated in the game.
     */
    void toggleAEDSignal(bool toggle);

    void updateLcdSignal(int rate);
};

#endif // CPR_MODEL_H
