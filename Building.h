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
        Building();
        ~Building();
        bool isOccupied();
        virtual void renovate() =0;
        virtual void demolish() =0;
        virtual void useElectricity();
        virtual void getElectricity();
        virtual void useWater();
        void addOccupant(Citizen* c);

};
#endif
