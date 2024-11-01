#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include <vector>
using namespace std;
#include "BuildingState.h"
class Citizen; //for now since Citizen is not defined
#include "Citizen.h"

class Building
{
    protected:
        BuildingState* state;
        string type;
        float area;
        float value;
        int floor; //dk how im going to use it now, 'cause im planning on adding a floor decorator
        float electricityUnits;
        float waterUnits;
        int capacity;
    public:
        Building(string type);
        virtual ~Building();
        virtual void loadElectricity(int units); //needs utilities
        virtual void loadWater(int units); //needs utilities
        virtual bool useElectricity(int units);
        virtual bool useWater(int units);
        virtual float getPrice();
        virtual string getType();
        virtual void demolish()=0;
        virtual bool clean()=0;
        virtual bool addOccupant(Citizen* c)=0;
        virtual Building* clone() =0;
        // virtual bool useToilet(); // why boolean, because when there isnt enough water/electricity it must affect the citizen
};
#endif
