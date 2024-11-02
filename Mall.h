#ifndef MALL_H
#define MALL_H
#include "Commercial.h"
class Citizen;
class Mall: public Commercial
{
    private:
        vector<Commercial*> stores;
        vector<Citizen*> owners;
        int noBuildings;
    public:
        Mall();
        ~Mall();
        bool addBuilding(Commercial*); //if capacity is reached, return false
        bool removeBuilding(Commercial *building);
        virtual void demolish();
        virtual bool clean();
        virtual bool addOccupant(Citizen *c);
        virtual bool removeOccupant(Citizen *c);
        virtual Building* clone();
        int getNoBuildings();
        virtual float getCleanliness();
        virtual float getWater();
        virtual float getElectricity();
        virtual bool isOccupied();
};
#endif