#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H
#include "Building.h"

class Residential : public Building
{

    public:
        Residential(string type);
        virtual bool addOccupant(Citizen *c)=0;
        // virtual void demolish() = 0; //inherited from Building, hence this class is abstract
        virtual bool useShower() = 0; // 
        virtual bool useToilet() = 0; // why boolean, because when there isnt enough water/electricity it must affect the citizen
        virtual bool useStove() = 0;  // why boolean, because when there isnt enough water/electricity it must affect the citizen
        virtual bool clean() = 0;     // why boolean, because when there isnt enough water/electricity it must affect the citizen

    // virtual void loadElectricity(int units); inherited from Building
    // virtual void loadWater(int units); inherited from Building
    // virtual bool useElectricity(int units); inherited from Building
    // virtual bool useWater(int units); inherited from Building
};
#endif
