#ifndef COMMERCIAL_H
#define COMMERCIAL_H
#include "Building.h"

class Commercial: public Building
{

    public:
        Commercial(string type);
        virtual void demolish() = 0;
        virtual bool clean()=0;
        virtual bool addOccupant(Citizen *c) =0;
        virtual bool removeOccupant(Citizen *c) = 0;
        virtual Building *clone() = 0;
        virtual bool isOccupied() = 0;
};
#endif