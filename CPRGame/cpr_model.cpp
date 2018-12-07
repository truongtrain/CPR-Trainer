/**
 * This is the CPR model class. The model interprets the actions sent from the
 * GUI and sends a result back to the GUI. This class handles the current state
 * of the game.
 */
#include "cpr_model.h"
#include <QDebug>
#include <QTimer>

/**
 * CPR constructor that simply initializes a few of our fields for the game.
 */
CPR_Model::CPR_Model(){}

/**
 * This is a slot that listens to the CPR actions performed from the view,
 * and decides if they were correct.
 */
void CPR_Model::actionPerformed(int action)
{
    // Advance the scenario if the action matches up with the current
    // state of the game
    if (action == currentState)
    {
        advanceSuccessfully();
    }
    // Advance the scenario if the action was a shout clear with appropriate conditions
    else if (action == SHOUT_CLEAR && (currentState == SHOUT_CLEAR_FOR_SHOCK || currentState == SHOUT_CLEAR_FOR_ANALYZE))
    {
        advanceSuccessfully();
    }
    else
    {
        emit isMoveCorrect(false);
        actionFailed();
    }
}

/**
 * Advances the current scenario if an action from the GUI was correct.
 */
void CPR_Model::advanceSuccessfully()
{
    if (currentState == CHECK_RESPONSIVENESS)
    {
      emit isMoveCorrect(true);

      // if the patient isn't conscious
      if (!isPatientConscious)
      {
        emit changeStatusBoxSignal("The patient does not respond to you.");
        emit changeTutorialBoxSignal("Someone should call 911 immediately and start searching for an AED.");

        // start a timer that makes the game fail if it goes off before the player performs a successful action
        setFailTimer(8000);

        // Advance the current state
        currentState = CALL_FOR_911_AND_AED;
        return;
      }

      // If the patient is conscious
      else
      {
        emit changeStatusBoxSignal("The patient wakes up and responds to you. Talk to them to see what they need. Game over, you win!");
        emit gameOverWinSignal("Game over, you win!");

        // Game is over, user has won.
        currentState = GAME_OVER;
        return;
      }
    }
    if (currentState == CALL_FOR_911_AND_AED)
    {
      emit isMoveCorrect(true);

      emit changeStatusBoxSignal("Bystanders call 911 and start looking for an AED");
      emit changeTutorialBoxSignal("Check to see if he is breathing or has a pulse.");

      // start a timer that makes the game fail if it goes off before the player performs a successful action
      setFailTimer(10000);

      // Advance the current state
      currentState = CHECK_PULSE_AND_BREATHING;
      return;
    }

    if (currentState == CHECK_PULSE_AND_BREATHING)
    {
      emit isMoveCorrect(true);

      // If the pateint has no pulse and is not breathing
      if (!doesPatientHavePulse && !isPatientBreathing)
      {
        emit changeStatusBoxSignal("Patient has no pulse and is not breathing");
        emit changeTutorialBoxSignal("Begin CPR. Start by giving him a breath.");

        // start a timer that makes the game fail if it goes off before the player performs a successful action;
        setFailTimer(10000);

        // Advance the current state
        currentState = GIVE_BREATH;
        breathsGiven = 0;
        return;
      }
      // If the patient has no pulse and is not breathing
      if (doesPatientHavePulse && !isPatientBreathing)
      {  

        emit changeStatusBoxSignal("Patient has a pulse, but is not breathing.");
        emit changeTutorialBoxSignal("Give one breath every 5 seconds.");

        // start a timer that makes the game fail if it goes off before the player performs a successful action
        setFailTimer(10000);

        // Advance the current state
        currentState = GIVE_BREATH;
        breathsGiven = 0;
        return;
      }

      // If the patient has a pulse and is breathing
      if (doesPatientHavePulse && isPatientBreathing)
      {
       emit changeStatusBoxSignal("Patient has a pulse and is breathing. Monitor their vitals until the ambulance arrives.");
       emit gameOverWinSignal("Game over, you win.");
       emit changeTutorialBoxSignal("Game over, you win.");

       // Game over, user has won
       currentState = GAME_OVER;
       return;
      }
    }

    if (currentState == GIVE_BREATH)
    {
      // Increment breaths given each time user selects "Give breaths"
      breathsGiven++;

      if (breathsGiven == 2)
      {
        emit isMoveCorrect(true);

        emit changeStatusBoxSignal("The breath makes the chest rise properly.");
        emit changeTutorialBoxSignal("Now give 30 compressions.");

        // start a timer that makes the game fail if it goes off before the player performs a successful action;
        setFailTimer(25000);

        // Advance the current scene if the user has given 2 breaths
        currentState = GIVE_COMPRESSION;
        compressionsGiven = 0;
        return;
      }

      if (breathsGiven == 1)
      {
        emit changeStatusBoxSignal("The breath makes the chest rise properly.");
        emit changeTutorialBoxSignal("Give another breath.");

        // start a timer that makes the game fail if it goes off before the player performs a successful action;
        setFailTimer(10000);

        return;
      }
    }

    if (currentState == GIVE_COMPRESSION)
    {
      // Increment compressions given each time user selects "give compression"
      compressionsGiven++;

      if (compressionsGiven < 30)
      {
        emit changeStatusBoxSignal("Compressions given: " + std::to_string(compressionsGiven) + "\nCompression Rate: NEED TO IMPLEMENT");
        emit changeTutorialBoxSignal("Keep your beats per minute between 100 and 120 beats per minute.");

        currentState = GIVE_COMPRESSION;
        return;
      }

      if (compressionsGiven == 30)
      {

         emit isMoveCorrect(true);

        // Increment cycles after breaths and compressions have been given
        cyclesCompleted++;
        emit changeStatusBoxSignal("Compressions given: " + std::to_string(compressionsGiven) + "\nCompression Rate: NEED TO IMPLEMENT");


        emit cursorChange();

        if (cyclesCompleted == 1)
        {
            emit changeTutorialBoxSignal("Now give two more breaths.");

            // start a timer that makes the game fail if it goes off before the player performs a successful action;
            setFailTimer(10000,GIVE_BREATH);

            // Need to give more breaths
            breathsGiven = 0;
            currentState = GIVE_BREATH;
            return;
        }
        // The AED arrives after two cycles
        else
        {

            emit changeStatusBoxSignal("The AED Arrives.");
            emit changeTutorialBoxSignal("Turn on the AED.");

            // start a timer that makes the game fail if it goes off before the player performs a successful action;
            setFailTimer(10000);

            // Activate AED
            breathsGiven = 0;
            currentState = TURN_ON_AED;
            cyclesCompleted = 0;
            emit toggleAEDSignal(true);

            return;
        }
      }
    }

    if (currentState == TURN_ON_AED)
    {
        emit isMoveCorrect(true);

        emit changeStatusBoxSignal("The AED turns on.");
        emit changeTutorialBoxSignal("Attach the pads to the patient's chest.");

        // start a timer that makes the game fail if it goes off before the player performs a successful action;
        setFailTimer(10000);

        // Advance the current state
        currentState = APPLY_PADS;
        return;
    }

    if (currentState == APPLY_PADS)
    {
        emit isMoveCorrect(true);
        emit cursorChange();
        emit changeStatusBoxSignal("The pads are attached to the patient. The AED says 'ANALYZING'");
        emit changeTutorialBoxSignal("Tell everyone to stay clear of the patient so you can let the AED analyze.");


        //start a timer that makes the game fail if it goes off before the player performs a successful action;
        setFailTimer(10000);

        // Advance the current state
        currentState = SHOUT_CLEAR_FOR_ANALYZE;
        return;
    }

    if (currentState == SHOUT_CLEAR_FOR_ANALYZE)
    {
        emit isMoveCorrect(true);

        emit changeStatusBoxSignal("The AED says 'SHOCK ADVISED'");
        emit changeTutorialBoxSignal("Tell everyone to stand clear for the shock.");

        // start a timer that makes the game fail if it goes off before the player performs a successful action;
        setFailTimer(10000);

        // Advance the current state
        currentState = SHOUT_CLEAR_FOR_SHOCK;
        return;
    }

    if (currentState == SHOUT_CLEAR_FOR_SHOCK)
    {
        emit isMoveCorrect(true);

        emit changeStatusBoxSignal("Everyone is standing clear.");
        emit changeTutorialBoxSignal("Press the shock button.");

        // start a timer that makes the game fail if it goes off before the player performs a successful action;
        setFailTimer(10000);

        // Advance the curreent state
        currentState = PRESS_SHOCK;
        return;
    }

    if (currentState == PRESS_SHOCK)
    {
        emit isMoveCorrect(true);

        emit changeStatusBoxSignal("He's alive!");
        emit gameOverWinSignal("The patient receives a shock. Do what the AED says until help arrives. Game Over, you win!");
        emit changeTutorialBoxSignal("");

        // Game over state, user wins
        currentState = GAME_OVER;
        return;
    }
}

/**
 * If pro mode is on, ends the game if the user selects the wrong action
 * in a given scenario.
 */
void CPR_Model::actionFailed()
{
    if(isProMode)
    {
       emit gameOverLoseSignal("Wrong Action. Game Over. Press New Game to start over.");
    }

    else
    {
        emit changeStatusBoxSignal("That was the wrong action.");
    }
}

/**
 * If pro mode is on, handles the action if the user runs out of time (game over).
 */
void CPR_Model::outOfTime(int failCondition)
{
    qDebug() << "timer went off";
    if (isProMode && currentState == failCondition && !(currentState == GAME_OVER))
    {
        qDebug() << "failed from timer";
        emit gameOverLoseSignal("You did not do the next action in time. Game over.");
        emit actionFailed();
    }
}

/**
 * Sets a time limit for each scenario if pro mode is on.
 */
void CPR_Model::setFailTimer(int interval,int failCondition)
{
    if(isProMode)
    {
        if(failCondition == -1)
        {
            failCondition = currentState + 1;
        }

        QTimer::singleShot(interval, this, [=]() {outOfTime(failCondition);});
    }
}

/**
 * Initializes a new game for our CPR game.
 */
void CPR_Model::newGame(bool isProMode)
{
    // Intialization
    qDebug() << "In newGame, pro mode is: "  + QString::number(isProMode);
    this->isProMode = isProMode;
    isPatientConscious = false;
    isPatientBreathing = false;
    doesPatientHavePulse = false;
    compressionsGiven = 0;
    breathsGiven = 0;
    cyclesCompleted = 0;
    currentState = CHECK_RESPONSIVENESS;

    emit changeStatusBoxSignal("You see this person collapse on the floor.");
    emit changeTutorialBoxSignal("Check to see if he's conscious.");
    emit toggleAEDSignal(false);
}


