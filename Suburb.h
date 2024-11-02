#ifndef SUBURB_H
#define SUBURB_H
#include "Residential.h"
#include "Building.h"
#include "Estate.h"
class Suburb : Residential
{
    private:
        vector<Residential*> buildings;
        int noBuildings; //
        int cleanliness; //
    public:
        Suburb();
        ~Suburb();
        virtual void loadElectricity(float units);
        virtual void loadWater(float units);
        virtual bool useElectricity(float units);
        virtual bool useWater(float units);
        virtual float getPrice();
        virtual string getType();
        virtual void demolish();
        virtual bool clean();
        virtual bool addOccupant(Citizen *c);
        virtual Building *clone();
        virtual bool removeOccupant(Citizen *c);
        virtual int getNoBuildings();
        virtual bool addBuilding(Residential* building);
        bool removeBuilding(Residential *building);
        virtual bool useShower();
        virtual bool useToilet();
        virtual bool useStove();
        virtual void goToWork();
        virtual bool isOccupied();
        virtual float getCleanliness();
        virtual float getWater();
        virtual float getElectricity(); 
};
#endif