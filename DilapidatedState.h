#ifndef DILAPIDATEDSTATE_H
#define DILAPIDATEDSTATE_H
#include "BuildingState.h"

class DilapidatedState : public BuildingState
{
    private:
    public:
        DilapidatedState();
        virtual ~DilapidatedState();
        virtual BuildingState* demolish(BuildingState *prevState);
        virtual BuildingState* renovate(BuildingState *prevState);
        virtual BuildingState* maintenance(BuildingState *prevState);
};
#endif
