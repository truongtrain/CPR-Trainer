#ifndef GAMESTATE_H
#define GAMESTATE_H


class GameState
{
    public:
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

    GameState();
};

#endif // GAMESTATE_H
