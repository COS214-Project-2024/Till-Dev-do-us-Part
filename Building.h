#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include <vector>
using namespace std;

class Citizen; //for now since Citizen is not defined

class Building
{
    protected:
        string type;
        float area;
        float electricityUnits;
        float waterUnits;
        int capacity;
        vector<Citizen*> occupants;
        // MaintenanceState* maintenance; //i think we should add this under BuildingState 

    public:
        Building(string name);
        ~Building();
        bool isOccupied();
        virtual void renovate()=0;
        virtual void demolish()=0;
        virtual void useElectricity()=0;
        virtual void useWater()=0;
        virtual void getElectricity();
        bool addOccupant(Citizen* c);

};
#endif
