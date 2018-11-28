#include "cpr_model.h"

CPR_Model::CPR_Model()
{
        isPatientConscious = false;
        isPatientBreathing = false;
        doesPatientHavePulse = false;

        //  initialize the game to the beginning

        currentState = CHECK_RESPONSIVENESS;
}

    //  this is a slot that listens to actions performed from the view
void CPR_Model::actionPerformed(int action)
{
    if (action == currentState)
       {
         advanceSuccessfully(action);
       }
       else
       {
         actionFailed(action);
       }
}

void CPR_Model::advanceSuccessfully(int action)
{
    if (currentState == CHECK_RESPONSIVENESS)
        {
          //    if the patient isn't conscious
          if (!isPatientConscious)
          {
             emit changeStatusBoxSignal("The patient does not respond to you.");


            //  start a timer that makes the game fail if it goes off before the player performs a successful action
            cout << "Timer started waiting for the user to call for an AED." << endl;

            currentState = CALL_FOR_911_AND_AED;
            return;
          }

          //    if the patient is conscious
          else
          {
            emit changeStatusBoxSignal("The patient wakes up and responds to you. Talk to them to see what they need. Game over, you win!");
            emit gameOverWinSignal("Game over, you win!");


            currentState = GAME_OVER;
            return;
          }
        }

        if (currentState == CALL_FOR_911_AND_AED)
        {
          emit changeStatusBoxSignal("Bystanders call 911 and start looking for an AED");
          cout << "The patient does not respond to you." << endl;

          //start a timer that makes the game fail if it goes off before the player performs a successful action;
          cout << "Timer started waiting for the user to check pulse and breathing." << endl;

          currentState = CHECK_PULSE_AND_BREATHING;
          return;
        }

        if (currentState == CHECK_PULSE_AND_BREATHING)
        {
          //    if no pulse and no breathing
          if (!doesPatientHavePulse && !isPatientBreathing)
          {
            emit changeStatusBoxSignal("Patient has no pulse and no breathing");

          }

          //    if has pulse and no breathing
          if (doesPatientHavePulse && !isPatientBreathing)
          {
            emit changeStatusBoxSignal("Patient has a pulse, but is not breathing.");

          }

          //    if has pulse and is breathing
          if (doesPatientHavePulse && isPatientBreathing)
          {
           emit changeStatusBoxSignal("Patient has a pulse and is breathing.");

          }

          //    start a timer that makes the game fail if it goes off before the player performs a successful action
          cout << "Timer started waiting for user to give breaths or compressions." << endl;

          currentState = CHECK_PULSE_AND_BREATHING;
          return;
        }
}

void CPR_Model::actionFailed(int action)
{
    if(isProMode)
    {
       emit gameOverLoseSignal("Game Over, you lose!");
    }
    else
    {
       emit changeStatusBoxSignal("Try again");
    }
}
