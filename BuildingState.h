#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

class BuildingState
{
    private:
        
    public:
        BuildingState();
        virtual ~BuildingState();
        virtual BuildingState* demolish(BuildingState* prevState) = 0;
        virtual BuildingState* renovate(BuildingState* prevState) = 0;
        virtual BuildingState* maintenance(BuildingState* prevState) = 0;
};
#endif

