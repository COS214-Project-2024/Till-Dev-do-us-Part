#ifndef CONSTRUCTIONSTATE_H
#define CONSTRUCTIONSTATE_H
#include "BuildingState.h"

class ConstructionState: public BuildingState
{
    private:
    public:
        ConstructionState();
        virtual ~ConstructionState();
        virtual BuildingState* demolish(BuildingState* prevState);
        virtual BuildingState* renovate(BuildingState *prevState);
        virtual BuildingState* maintenance(BuildingState *prevState);
};
#endif
