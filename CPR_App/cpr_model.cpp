#include "cpr_model.h"
#include <QDebug>

CPR_Model::CPR_Model()
{
    newGame();
    isProMode = false;
}

// This is a slot that listens to the CPR actions performed from the view, and decides if they were correct.
void CPR_Model::actionPerformed(int action)
{
    if (action == currentState)
    {
        advanceSuccessfully();
    }

   else
   {
        actionFailed(action);
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

        currentState = GIVE_COMPRESSION;
        compressionsGiven = 0;
        return;
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

              currentState = GIVE_BREATH;
              cyclesCompleted++;
              return;
          }

          // the AED arrives after two cycles
          else
          {
              emit changeStatusBoxSignal("The AED Arrives.");
              qDebug() << "The AED Arrives.";

              emit changeTutorialBoxSignal("Turn on the AED.");

              currentState = TURN_ON_AED;
              cyclesCompleted = 0;
              return;
          }
        }
      }
    }
}

void CPR_Model::actionFailed(int action)
{
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
    }

    else
    {

       emit changeTutorialBoxSignal("Wrong action. Try again.");
    }
}

void CPR_Model::newGame()
{
    isPatientConscious = false;
    isPatientBreathing = false;
    doesPatientHavePulse = false;

    currentState = CHECK_RESPONSIVENESS;

    emit changeStatusBoxSignal("You see this person collapse on the floor.");
    emit changeTutorialBoxSignal("Check to see if he's conscious.");
}

void CPR_Model::changeProModeStatus(bool changeStatus)
{
    isProMode = changeStatus;
}
