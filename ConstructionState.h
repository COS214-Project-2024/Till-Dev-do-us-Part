#ifndef CONSTRUCTIONSTATE_H
#define CONSTRUCTIONSTATE_H
#include "BuildingState.h"
#include "CompleteState.h"

class ConstructionState: public BuildingState{
    public:
        ConstructionState();
        virtual bool canUseElectricity();
        virtual bool canUseWater();
        virtual BuildingState* change();
};
#endif
