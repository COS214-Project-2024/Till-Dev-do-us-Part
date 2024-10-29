#ifndef SHORTAGE_STATE_H
#define SHORTAGE_STATE_H
#include "BalancedState.h"
#include "CriticalState.h"
#include "ResourceState.h"
#include "Resources.h"

class ShortageState:public ResourceState{
    public :
         virtual void checkAvailability(Resources* resource);
        virtual string getStatus();
};

#endif