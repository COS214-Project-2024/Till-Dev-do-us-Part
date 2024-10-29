#include "ShortageState.h"

void ShortageState::checkAvailability(Resources* resource)
{
     float ratio = (resource->getCurrentAmount() / resource->getInitialAmount()) * 100;
    
     if (ratio >= 50 && ratio<99) {
        resource->setState(new BalancedState());
    }
    else if(ratio>=100)
    {
        resource->setState(new SurplusState());
    }
    else if (ratio < 25) 
    {
        resource->setState(new CriticalState());
    }
      else {
            resource->alert();  
        }
}

string ShortageState::getStatus()
{
    return "Shortage State";
}
