#include "FleeCuzOfStress.h"
#include "../Raven_SteeringBehaviors.h"
#include "../navigation/Raven_PathPlanner.h"
#include "Debug/DebugConsole.h"
#include "Goal_Wander.h"


// FleeCuzOfStress
// When his HP are low there is a chance that the bot may become crazy because of stress instead of going after health item

//------------------------------- Activate ------------------------------------
//-----------------------------------------------------------------------------
void FleeCuzOfStress::Activate() {
    m_iStatus = active;

    // If not fleeing, init flee
    if (!isFleeing && m_pOwner->Health() <= 10) {
        initFlee();
        isFleeing = true;
    }
    else 
    {
        isFleeing = false;
    }

}

//------------------------------- Process -------------------------------------
//-----------------------------------------------------------------------------
int FleeCuzOfStress::Process() {

    // Active goal if inactive
    ActivateIfInactive();

    // Abort if the health is superior to 10
    if (m_pOwner->Health() > 10)
    {
        Terminate();
        m_iStatus = failed;

    }
    else
    {
        if (!isFleeing && m_pOwner->Health() <= 10) 
        {
            RemoveAllSubgoals();
            initFlee();
            isFleeing = true;
        }
        else if (isFleeing && m_pOwner->Health() > 10)
        {
            // The bots walked on HP and got healed
            Terminate();
            isFleeing = false;
        }
    }
    
    return m_iStatus;

}

//------------------------------- Terminate -------------------------------------
//-------------------------------------------------------------------------------
void FleeCuzOfStress::Terminate() {
    // Finish the dodge (if dodging)
    if (isFleeing) 
    {
        m_pOwner->GetSteering()->WanderOff();
    }
}


void FleeCuzOfStress::initFlee() {

    m_pOwner->GetSteering()->WanderOn();
}
