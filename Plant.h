#ifndef PLANT_H
#define PLANT_H
#include "Industrial.h"

class Plant : public Industrial
{
    private:
        vector<Industrial *> buildings;

    public:
        Plant();
        ~Plant();
        virtual void demolish();
        virtual bool clean();
        bool addOccupant(Citizen *c, string type);
        bool addBuilding(Industrial *); // if capacity is reached, return false
};
#endif
