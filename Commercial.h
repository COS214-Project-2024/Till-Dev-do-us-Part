#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H
#include "Building.h"

class Commercial: public Building
{

    public:
        Commercial(string type);
        ~Commercial();
        virtual void demolish() = 0;
        virtual bool clean()=0;
        virtual bool addOccupant(Citizen *c) =0;
        // bool isOccupied(); TODO
};
#endif

