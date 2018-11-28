#ifndef CPR_MODEL_H
#define CPR_MODEL_H

#include <QObject>
#include <iostream>

using namespace std;

class CPR_Model : public QObject
{
    Q_OBJECT

public:
    CPR_Model();

public slots:
    void actionPerformed(int);

private:
    int currentState;

    const int CHECK_RESPONSIVENESS  = 0;
    const int CALL_FOR_911_AND_AED = 1;
    const int CHECK_PULSE_AND_BREATHING = 2;
    const int GIVE_BREATH = 3;
    const int PLACE_HANDS = 4;
    const int GIVE_COMPRESSION = 5;
    const int TURN_ON_AED = 6;
    const int ATTATCH_AED_PAD_1 = 7;
    const int ATTATCH_AED_PAD_2 = 8;
    const int SHOUT_CLEAR_FOR_ANALYZE = 9;
    const int PRESS_ANALYZE = 10;
    const int SHOUT_CLEAR_FOR_SHOCK = 11;
    const int PRESS_SHOCK = 12;
    const int GAME_OVER = 13;

    bool isPatientConscious;
    bool doesPatientHavePulse;
    bool isPatientBreathing;
    bool isProMode;

    int compressionsGiven;
    int breathsGiven;


    //  helper methods
    void advanceSuccessfully(int action);
    void actionFailed(int action);

signals:
    void changeStatusBoxSignal(string message);
    void gameOverWinSignal(string message);
    void gameOverLoseSignal(string message);

};

#endif // CPR_MODEL_H


