#ifndef INDUSTRIALSITE_H
#define INDUSTRIALSITE_H
#include "Industrial.h"
#include "Building.h"
#include "Plant.h"
class IndustrialSite : public Industrial
{
    private:
        vector<Industrial*> buildings;
        int noBuildings; //
        int cleanliness; //
    public:
        IndustrialSite();
        ~IndustrialSite();
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
        virtual bool addBuilding(Industrial* building);
        bool removeBuilding(Industrial *building);
        virtual bool isOccupied();
        virtual float getCleanliness();
        virtual float getWater();
        virtual float getElectricity();        
};
#endif
