#include "CriticalState.h"

void CriticalState::checkAvailability(Resources* resource)
{
  float ratio = (resource->getCurrentAmount() / resource->getInitialAmount()) * 100;
    
    if (ratio >=25 && ratio<50) 
    {
        resource->setState(new ShortageState());
    }
    else if (ratio>=50 && ratio<100)
    {
        resource->setState(new BalancedState());
    }
    else if(ratio >=100)
    {
        resource->setState(new SurplusState());
    }
      else {
            resource->notifyObservers();  // Log even when staying in surplus
        }
    }

string CriticalState::getStatus()
{
    return "Critical State";
}

 
