#ifndef DILAPIDATEDSTATE_H
#define DILAPIDATEDSTATE_H
#include "BuildingState.h"

class DilapidatedState : public BuildingState
{
    private:
    public:
        DilapidatedState();
        virtual ~DilapidatedState();
        virtual bool canUseElectricity();
        virtual bool canUseWater();
        virtual BuildingState *change();
};
#endif