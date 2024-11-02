#ifndef PUBLIC_H
#define PUBLIC_H
#include "Building.h"

class Public : public Building
{
    public:
        Public(string type) : Building(type) {}
        virtual bool addOccupant(Citizen *c) = 0;
        virtual void demolish() = 0;             
        virtual bool clean() = 0;
        virtual bool removeOccupant(Citizen *c) = 0;
        virtual Building *clone() = 0;
        virtual bool isOccupied() = 0;
};
#endif