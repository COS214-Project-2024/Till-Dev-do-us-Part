#ifndef COMPLETESTATE_H
#define COMPLETESTATE_H
#include "BuildingState.h"

class CompleteState : public BuildingState
{
    private:
    public:
        CompleteState();
        virtual bool canUseElectricity();
        virtual bool canUseWater();
        virtual BuildingState *change();
};
#endif
