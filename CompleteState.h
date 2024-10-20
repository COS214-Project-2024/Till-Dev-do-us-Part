#ifndef COMPLETESTATE_H
#define COMPLETESTATE_H
#include "BuildingState.h"

class CompleteState : public BuildingState
{
    private:
    public:
        CompleteState();
        virtual ~CompleteState();
        virtual BuildingState* demolish(BuildingState *prevState);
        virtual BuildingState* renovate(BuildingState *prevState);
        virtual BuildingState* maintenance(BuildingState *prevState);
};
#endif
