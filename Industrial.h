#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H
#include "Building.h"

class Industrial : public Building
{
    public:
        Industrial(string type) : Building(type) {}
        virtual bool addOccupant(Citizen *c) = 0;
        virtual bool removeOccupant(Citizen *c) = 0;
        virtual void demolish() = 0;
        virtual bool clean() = 0;
        virtual Building *clone() = 0;
        virtual bool isOccupied() = 0;
};
#endif