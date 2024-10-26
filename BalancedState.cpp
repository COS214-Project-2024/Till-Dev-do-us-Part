#include "BalancedState.h"

void BalancedState::checkAvailability(Resources* resource)
{
     float ratio = (resource->getCurrentAmount() / resource->getInitialAmount()) * 100;
    
     if (ratio >=100) {
        resource->setState(new SurplusState());
    }
    else if (ratio < 50&& ratio >=25) {
        resource->setState(new ShortageState());
    }
    else if(ratio<25)
    {
        resource->setState(new CriticalState());
    }
      else {
            resource->notifyObservers();  // Log even when staying in surplus
        }
}

string BalancedState::getStatus()
{
    return "Balanced State ";
}
