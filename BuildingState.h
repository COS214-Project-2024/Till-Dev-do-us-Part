#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H
#include <iostream>
using namespace std;

class BuildingState
{
    protected:
        string name;
    public:
        BuildingState();
        virtual ~BuildingState();
        virtual string getName();
        virtual BuildingState* demolish(BuildingState* prevState) = 0;
        virtual BuildingState* renovate(BuildingState* prevState) = 0;
        virtual BuildingState* maintenance(BuildingState* prevState) = 0;
};
#endif


