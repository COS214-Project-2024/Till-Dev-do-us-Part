// #include "Citizen.h"
#ifndef BUILDING_H
#define BUILDING_H

#include "BuildingState.h"
#include "ConstructionState.h"
#include "CompleteState.h"
#include "DilapidatedState.h"
#include "ResourceDepartment.h"
// #include "Citizen.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Citizen;
class Building
{
    protected:
        BuildingState* state;
        string type;
        float cleanliness;
        float electricityUnits;
        float waterUnits;
        float value; //
        float area; //
        int capacity; //
        ResourceDepartment * resDept;
    public:
        Building(string type);
        virtual ~Building();
        virtual void loadElectricity(float units);
        virtual void loadWater(float units);
        virtual bool useElectricity(float units);
        virtual bool useWater(float units);
        virtual float getValue();
        virtual string getType();
        virtual float getWater();
        virtual float getElectricity();
        virtual float getCleanliness();
        virtual void demolish()=0;
        virtual bool clean()=0;
        virtual bool addOccupant(Citizen* c)=0;
        virtual bool removeOccupant(Citizen* c)=0;
        virtual Building* clone() =0;
        virtual bool isOccupied() =0;
        virtual void consume();

};
#endif