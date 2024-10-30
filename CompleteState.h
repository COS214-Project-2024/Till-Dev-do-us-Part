#ifndef COMPLETESTATE_H
#define COMPLETESTATE_H
#include "BuildingState.h"

class CompleteState : public BuildingState
{
    public:
        CompleteState();
        virtual bool canUseElectricity();
        virtual bool canUseWater();
};
#endif
