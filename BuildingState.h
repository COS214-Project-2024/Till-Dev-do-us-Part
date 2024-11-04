#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H
#include <iostream>
using namespace std;

class BuildingState
{
    protected:
        string name;
    public:
        BuildingState(string name);
        virtual ~BuildingState();
        virtual bool canUseElectricity()=0;
        virtual bool canUseWater()=0;
        virtual BuildingState* clone() = 0;
        virtual string getName();
};
#endif