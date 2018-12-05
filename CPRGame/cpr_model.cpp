#include "cpr_model.h"
#include <QDebug>
#include <QTimer>

CPR_Model::CPR_Model()
{
    currentTimer = new QTimer(this);
    newGame();
    isProMode = false;
}

// This is a slot that listens to the CPR actions performed from the view, and decides if they were correct.
void CPR_Model::actionPerformed(int action)
{
    qDebug() << "Action has been performed: " << action;
    if (action == currentState)
    {
        advanceSuccessfully();

        if (currentTimer->isActive())
        {
            currentTimer->stop();
        }
    }

   else if (action == SHOUT_CLEAR && (currentState == SHOUT_CLEAR_FOR_SHOCK || currentState == SHOUT_CLEAR_FOR_ANALYZE))
   {
        advanceSuccessfully();
   }
}

void CPR_Model::advanceSuccessfully()
{
    if (currentState == CHECK_RESPONSIVENESS)
    {
      // if the patient isn't conscious
      if (!isPatientConscious)
      {
         emit changeStatusBoxSignal("The patient does not respond to you.");
         qDebug() << "The patient does not respond to you.";

         emit changeTutorialBoxSignal("Someone should call 911 immediately and start searching for an AED.");

        //  start a timer that makes the game fail if it goes off before the player performs a successful action
        qDebug() << "Timer started waiting for the user to call for an AED.";
        setFailTimer(10000);

        currentState = CALL_FOR_911_AND_AED;
        return;
      }

      // if the patient is conscious
      else
      {
        emit changeStatusBoxSignal("The patient wakes up and responds to you. Talk to them to see what they need. Game over, you win!");
        qDebug() << "The patient wakes up and responds to you. Talk to them to see what they need. Game over, you win!";

        emit gameOverWinSignal("Game over, you win!");

        currentState = GAME_OVER;
        return;
      }
    }

    if (currentState == CALL_FOR_911_AND_AED)
    {
      emit changeStatusBoxSignal("Bystanders call 911 and start looking for an AED");
      qDebug() << "Bystanders call 911 and start looking for an AED";

      emit changeTutorialBoxSignal("Check to see if he is breathing or has a pulse.");

      //start a timer that makes the game fail if it goes off before the player performs a successful action;
      qDebug() << "Timer started waiting for the user to check pulse and breathing.";
      setFailTimer(10000);

      currentState = CHECK_PULSE_AND_BREATHING;
      return;
    }

    if (currentState == CHECK_PULSE_AND_BREATHING)
    {
      // if no pulse and no breathing
      if (!doesPatientHavePulse && !isPatientBreathing)
      {
        emit changeStatusBoxSignal("Patient has no pulse and is not breathing");
        qDebug() << "Patient has no pulse and is not breathing";

        emit changeTutorialBoxSignal("Begin CPR. Start by giving him a breath.");

        //start a timer that makes the game fail if it goes off before the player performs a successful action;
        qDebug() << "Timer started waiting for the user to give a breath.";
        setFailTimer(10000);

        currentState = GIVE_BREATH;
        breathsGiven = 0;
        return;
      }

      // if has pulse and is not breathing
      if (doesPatientHavePulse && !isPatientBreathing)
      {
        emit changeStatusBoxSignal("Patient has a pulse, but is not breathing.");
        qDebug() << "Patient has a pulse, but is not breathing";

        emit changeTutorialBoxSignal("Give one breath every 5 seconds.");

        // start a timer that makes the game fail if it goes off before the player performs a successful action
        qDebug() << "Timer started waiting for user to give a breath.";
        setFailTimer(10000);

        currentState = GIVE_BREATH;
        breathsGiven = 0;
        return;
      }

      // if has pulse and is breathing
      if (doesPatientHavePulse && isPatientBreathing)
      {
       emit changeStatusBoxSignal("Patient has a pulse and is breathing. Monitor their vitals until the ambulance arrives.");
       qDebug() << "Patient has a pulse and is breathing. Monitor their vitals until the ambulance arrives.";

       emit gameOverWinSignal("Game over, you win.");

       emit changeTutorialBoxSignal("Game over, you win.");

       currentState = GAME_OVER;
       return;
      }
    }

    if (currentState == GIVE_BREATH)
    {
      breathsGiven++;

      if (breathsGiven == 2)
      {
        emit changeStatusBoxSignal("The breath makes the chest rise properly.");
        qDebug() << "The breath makes the chest rise properly.";

        emit changeTutorialBoxSignal("Now give 30 compressions.");

        //start a timer that makes the game fail if it goes off before the player performs a successful action;
        qDebug() << "Timer started waiting for the user to give compressions.";
        setFailTimer(10000);

        currentState = GIVE_COMPRESSION;
        compressionsGiven = 0;
        return;
      }

      if (breathsGiven == 1)
      {
        emit changeStatusBoxSignal("The breath makes the chest rise properly.");
        qDebug() << "The breath makes the chest rise properly.";

        emit changeTutorialBoxSignal("Give another breath.");

        //start a timer that makes the game fail if it goes off before the player performs a successful action;
        qDebug() << "Timer started waiting for the user to give compressions.";
        setFailTimer(10000);

        return;
      }
    }

    if (currentState == GIVE_COMPRESSION)
    {
      compressionsGiven++;

      if (compressionsGiven < 30)
      {
        emit changeStatusBoxSignal("Compressions given: " + std::to_string(compressionsGiven) + "\nCompression Rate: NEED TO IMPLEMENT");
        qDebug() << "Compressions given: " << compressionsGiven << "\nCompression Rate: NEED TO IMPLEMENT";

        emit changeTutorialBoxSignal("Keep your beats per minute between 100 and 120 beats per minute.");

        currentState = GIVE_COMPRESSION;
        return;
      }

      if (compressionsGiven == 30)
      {
          cyclesCompleted++;

          emit changeStatusBoxSignal("Compressions given: " + std::to_string(compressionsGiven) + "\nCompression Rate: NEED TO IMPLEMENT");
          qDebug() << "Compressions given: " << compressionsGiven << "\nCompression Rate: NEED TO IMPLEMENT";

        if (cyclesCompleted == 1)
        {
            emit changeTutorialBoxSignal("Now give two more breaths.");

            //start a timer that makes the game fail if it goes off before the player performs a successful action;
            qDebug() << "Timer started waiting for the user to give breaths.";
            setFailTimer(10000);

            breathsGiven = 0;
            currentState = GIVE_BREATH;
            return;
        }

        // the AED arrives after two cycles
        else
        {
            emit changeStatusBoxSignal("The AED Arrives.");
            qDebug() << "The AED Arrives.";

            emit changeTutorialBoxSignal("Turn on the AED.");

            //start a timer that makes the game fail if it goes off before the player performs a successful action;
            qDebug() << "Timer started waiting for the user to give compressions.";
            setFailTimer(10000);

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
        emit changeStatusBoxSignal("The AED turns on.");
        qDebug() << "The AED turns on.";

        emit changeTutorialBoxSignal("Attach the pads to the patient's chest.");

        //start a timer that makes the game fail if it goes off before the player performs a successful action;
        qDebug() << "Timer started waiting for the user to apply the pads.";
        setFailTimer(10000);

        currentState = APPLY_PADS;
        return;
    }

    if (currentState == APPLY_PADS)
    {
        emit changeStatusBoxSignal("The pads are attached to the patient. The AED says 'ANALYZING'");
        qDebug() << "The pads are attached to the patient.";

        emit changeTutorialBoxSignal("Tell everyone to stay clear of the patient so you can let the AED analyze.");

        //start a timer that makes the game fail if it goes off before the player performs a successful action;
        qDebug() << "Timer started waiting for the user to shout clear for analyze";
        setFailTimer(10000);

        currentState = SHOUT_CLEAR_FOR_ANALYZE;
        return;
    }

    if (currentState == SHOUT_CLEAR_FOR_ANALYZE)
    {
        emit changeStatusBoxSignal("The AED says 'SHOCK ADVISED'");

        emit changeTutorialBoxSignal("Tell everyone to stand clear for the shock.");

        //start a timer that makes the game fail if it goes off before the player performs a successful action;
        qDebug() << "Timer started waiting for the user to press the analyze button.";
        setFailTimer(10000);

        currentState = SHOUT_CLEAR_FOR_SHOCK;
        return;
    }

    if (currentState == SHOUT_CLEAR_FOR_SHOCK)
    {
        emit changeStatusBoxSignal("Everyone is standing clear.");
        qDebug() << "Everyone is standing clear.";

        emit changeTutorialBoxSignal("Press the shock button.");

        //start a timer that makes the game fail if it goes off before the player performs a successful action;
        qDebug() << "Timer started waiting for the user to press the shock button.";
        setFailTimer(10000);

        currentState = PRESS_SHOCK;
        return;
    }

    if (currentState == PRESS_SHOCK)
    {
        emit changeStatusBoxSignal("He's alive!");
        emit gameOverWinSignal("The patient receives a shock. Do what the AED says until help arrives. Game Over, you win!");
        qDebug() << "The patient receives a shock.";

        emit changeTutorialBoxSignal("");

        currentState = GAME_OVER;
        return;
    }
}

void CPR_Model::actionFailed()
{
    qDebug() << "Wrong action entered.";
    if(currentState == GAME_OVER)
    {
        emit changeStatusBoxSignal("The game is over. Press new game to play again.");
        qDebug() << "The game is over. Press new game to play again.";

        emit changeTutorialBoxSignal("");
        return;
    }

    if(isProMode)
    {
       emit gameOverLoseSignal("Wrong Action. Game Over. Press New Game to start over.");
       currentTimer->stop();
    }

    if(!isProMode)
    {
        emit changeStatusBoxSignal("That was the wrong action.");
    }
}

void CPR_Model::outOfTime()
{
    if (isProMode)
    {
        emit gameOverLoseSignal("You did not do the next action in time. Game over.");
    }
}

void CPR_Model::setFailTimer(int interval)
{
    if(isProMode)
    {
        if (currentTimer->isActive())
        {
            currentTimer->stop();
        }

        currentTimer->setSingleShot(true);
        connect(currentTimer, SIGNAL(timeout()), this, SLOT(outOfTime()));
        currentTimer->start(interval);
    }
}

void CPR_Model::newGame()
{
    isPatientConscious = false;
    isPatientBreathing = false;
    doesPatientHavePulse = false;

    compressionsGiven = 0;
    breathsGiven = 0;
    cyclesCompleted = 0;

    currentState = CHECK_RESPONSIVENESS;

    emit changeStatusBoxSignal("You see this person collapse on the floor.");
    emit changeTutorialBoxSignal("Check to see if he's conscious.");
}

void CPR_Model::changeProModeStatus(bool changeStatus)
{
    isProMode = changeStatus;
}
