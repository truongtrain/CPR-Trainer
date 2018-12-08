/**
 * This is the CPR model class. The model interprets the actions sent from the
 * GUI and sends a result back to the GUI. This class handles the current state
 * of the game.
 */

#include "cpr_model.h"
#include <QTimer>
#include <QDir>

CPR_Model::CPR_Model()
{
    timeLeft = 20;
    QTimer::singleShot(8000, this, [=]() {displayTimeLeft();});
    metronome.setDesiredRate(110);
    metronome.setDesiredTolerance(20);

    stayinAlive = new QMediaPlayer;
    stayinAlive->setMedia(QUrl("qrc:/sounds/stayinAlive.mp3"));
    stayinAlive->setVolume(100);
}


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

        timeLeft = 8;

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

      timeLeft = 10;

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

        timeLeft = 10;

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

        timeLeft = 10;

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

        timeLeft = 25;

        // Advance the current scene if the user has given 2 breaths
        currentState = GIVE_COMPRESSION;
        compressionsGiven = 0;
        if (!isProMode)
        {
            stayinAlive->play();
        }
        return;
      }

      if (breathsGiven == 1)
      {
        emit changeStatusBoxSignal("The breath makes the chest rise properly.");
        emit changeTutorialBoxSignal("Give another breath.");

        timeLeft = 10;

        return;
      }
    }

    if (currentState == GIVE_COMPRESSION)
    {
      // Increment compressions given each time user selects "give compression"
      compressionsGiven++;

      if (compressionsGiven == 1)
      {
          metronome.start();
          badCompressionsRateCount = 0; // Reset any previous mistakes made because of a bad compression rate
      }
      else if (compressionsGiven < 30)
      {
          emit changeStatusBoxSignal("Compressions given: " + std::to_string(compressionsGiven));

          int tickRate = metronome.receiveTick();

          if (isProMode && (!metronome.isTickRateWithinTolerance()))
          {
              badCompressionsRateCount++;
              if (badCompressionsRateCount >= 10)
              {
                  emit gameOverLoseSignal("");    // Too many compressions at the wrong rate.
              }
          }

          emit updateLcdSignal(tickRate);

          emit changeTutorialBoxSignal("Keep your beats per minute between 100 and 120 beats per minute.");

          currentState = GIVE_COMPRESSION;
          return;
        }

      if (compressionsGiven == 30)
      {
          stayinAlive->stop();
        emit updateLcdSignal(0); // Reset compresion rate display

         emit isMoveCorrect(true);

        // Increment cycles after breaths and compressions have been given
        cyclesCompleted++;
        emit changeStatusBoxSignal("Compressions given: " + std::to_string(compressionsGiven) + "\nCompression Rate: NEED TO IMPLEMENT");


        emit cursorChange();

        if (cyclesCompleted == 1)
        {
            emit changeTutorialBoxSignal("Now give two more breaths.");

            timeLeft = 10;

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

            timeLeft = 10;

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

        timeLeft = 15;

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

        timeLeft = 10;

        // Advance the current state
        currentState = SHOUT_CLEAR_FOR_ANALYZE;
        return;
    }

    if (currentState == SHOUT_CLEAR_FOR_ANALYZE)
    {
        emit isMoveCorrect(true);

        emit changeStatusBoxSignal("The AED says 'SHOCK ADVISED'");
        emit changeTutorialBoxSignal("Tell everyone to stand clear for the shock.");

        timeLeft = 10;

        // Advance the current state
        currentState = SHOUT_CLEAR_FOR_SHOCK;
        return;
    }

    if (currentState == SHOUT_CLEAR_FOR_SHOCK)
    {
        emit isMoveCorrect(true);

        emit changeStatusBoxSignal("Everyone is standing clear.");
        emit changeTutorialBoxSignal("Press the shock button.");

        timeLeft = 10;

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
 * Initializes a new game for our CPR game.
 */
void CPR_Model::newGame(bool isProMode)
{
    // Intialization
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

    timeLeft = 20;
}

void CPR_Model::displayTimeLeft()
{
    if (isProMode)
    {
        emit changeTimeLeftSignal(timeLeft--);
        if (timeLeft == -1 && currentState != GAME_OVER)
        {
            emit gameOverLoseSignal("");
        }
    }

    else
    {
        emit changeTimeLeftSignal(0);
    }

    QTimer::singleShot(1000, this, [=]() {displayTimeLeft();});
}


