#ifndef CPR_MODEL_H
#define CPR_MODEL_H

#include <QObject>
#include <iostream>
#include <QTimer>

// The purpose of the CPR Model is to keep track of the
// patient status. Each different state must tell the View to update
// itself based on the model current state.

using namespace std;

class CPR_Model : public QObject
{
    Q_OBJECT

public:
    CPR_Model();

private:
    int currentState;

    const int CHECK_RESPONSIVENESS  = 0;
    const int CALL_FOR_911_AND_AED = 1;
    const int CHECK_PULSE_AND_BREATHING = 2;
    const int GIVE_BREATH = 3;
    const int PLACE_HANDS = 4;
    const int GIVE_COMPRESSION = 5;
    const int TURN_ON_AED = 6;
    const int APPLY_PADS = 7;
    const int SHOUT_CLEAR_FOR_ANALYZE = 8;
    const int PRESS_ANALYZE = 9;
    const int SHOUT_CLEAR_FOR_SHOCK = 10;
    const int PRESS_SHOCK = 11;
    const int GAME_OVER = 12;

    QTimer* currentTimer;

    bool isPatientConscious;
    bool doesPatientHavePulse;
    bool isPatientBreathing;
    bool isProMode;

    int compressionsGiven;
    int breathsGiven;
    int cyclesCompleted;

    //  helper methods
    void advanceSuccessfully();
    void actionFailed();
    void outOfTime();
    void setFailTimer(int interval);

public slots:
    void actionPerformed(int);
    void changeProModeStatus(bool);
    void newGame();

signals:
    void changeStatusBoxSignal(string message);
    void changeTutorialBoxSignal(string message);
    void gameOverWinSignal(string message);
    void gameOverLoseSignal(string message);

};

#endif // CPR_MODEL_H


