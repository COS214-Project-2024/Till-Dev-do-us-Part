#ifndef PLANT_H
#define PLANT_H
#include "Industrial.h"

class Plant : public Industrial
{
    private:
        vector<Industrial *> buildings;
        int noBuildings;

    public:
        Plant();
        ~Plant();
        virtual void demolish();
        virtual bool clean();
        virtual bool addOccupant(Citizen *c);
        virtual bool removeOccupant(Citizen *c);
        virtual bool addBuilding(Industrial *);
        virtual bool removeBuilding(Industrial *);
        virtual Building *clone();
        virtual float getCleanliness();
        virtual float getWater();
        virtual float getElectricity();
        virtual bool isOccupied();
        virtual int getNoBuildings();
};
#endif