#ifndef CRITICAL_STATE_H
#define CRITICAL_STATE_H

#include "ShortageState.h"
class Resources;
#include "ResourceState.h"

class CriticalState:public ResourceState{
    public :
          void checkAvailability(Resources* res) override;
         string getStatus()override;
};

#endif