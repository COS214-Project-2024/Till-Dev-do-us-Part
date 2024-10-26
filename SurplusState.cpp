#include "SurplusState.h"

void SurplusState::checkAvailability(Resources* resource)
{
     float ratio = (resource->getCurrentAmount() / resource->getInitialAmount()) * 100;
    
    if (ratio < 100) 
    {  
         if (ratio >= 50) 
      {
        resource->setState(new BalancedState());
       }
       else if(ratio < 50 && ratio>=25) {
        resource->setState(new ShortageState());}
        else 
        {
            resource->setState(new CriticalState());
        }
    }
     
     
    
     else {
            resource->notifyObservers();  // Log even when staying in surplus
        }
}

string SurplusState::getStatus()
{
    return "Surplus State";
}
