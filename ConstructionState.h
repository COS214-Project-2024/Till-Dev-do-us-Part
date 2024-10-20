#ifndef CONSTRUCTIONSTATE_H
#define CONSTRUCTIONSTATE_H
#include "BuildingState.h"

class ConstructionState: public BuildingState
{
    private:
    public:
        ConstructionState();
        virtual ~ConstructionState();
        virtual ConstructionState* demolish(BuildingState* prevState);
        virtual ConstructionState *renovate(BuildingState *prevState);
        virtual ConstructionState *maintenance(BuildingState *prevState);
};
#endif
