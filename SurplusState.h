#ifndef SURPLUS_STATE_H
#define SURPLUS_STATE_H

#include "BalancedState.h"
#include "ResourceState.h"
#include "Resources.h"


class SurplusState:public ResourceState{
    public :
            void checkAvailability(Resources* resource) override;
         string getStatus() override;
};

#endif