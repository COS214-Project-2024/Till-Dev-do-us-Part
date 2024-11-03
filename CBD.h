#ifndef CBD_H
#define CBD_H
#include "Commercial.h"
// #include "Building.h"
#include "Mall.h"
class CBD : public Commercial
{
    private:
        vector<Building*> buildings;
        int noBuildings; //
        int cleanliness; //
    public:
        CBD();
        ~CBD();
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
        virtual bool addBuilding(Building* building);
        virtual bool removeBuilding(Building *);
        virtual bool isOccupied();
        virtual float getCleanliness();
        virtual float getWater();
        virtual float getElectricity();        
};
#endif
