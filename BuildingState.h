#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

class BuildingState
{
    private:
        
    public:
        BuildingState();
        virtual ~BuildingState();
        virtual BuildingState* demolish()=0;
        virtual BuildingState* renovate()=0;
        virtual BuildingState* maintenance()=0;
};
#endif

