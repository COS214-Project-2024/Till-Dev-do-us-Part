#ifndef BALANCED_STATE_H
#define BALANCED_STATE_H

#include "ShortageState.h"
#include "ResourceState.h"
class Resources;

class BalancedState:public ResourceState{
    public :
         void checkAvailability(Resources* res) override;
         string getStatus() override;
};

#endif