#ifndef ESTATE_H
#define ESTATE_H
#include "Residential.h"
#include "Building.h"


class Estate : public Residential
{
    private:
        vector<Residential *> buildings;
        int noBuildings;

    public:
        Estate();
        ~Estate();
        virtual void demolish();
        virtual bool useShower();
        virtual bool useToilet();
        virtual bool useStove();
        virtual bool clean();
        bool addOccupant(Citizen *c);
        bool addHouse(Residential *);
        virtual void goToWork();
        virtual int getNoBuildings();
        virtual bool removeOccupant(Citizen *c);
        bool removeBuilding(Residential *building);
        virtual Building *clone();
        virtual bool isOccupied();
        virtual float getCleanliness();
        virtual float getWater();
        virtual float getElectricity();
    };
#endif