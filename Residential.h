#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H
#include "Building.h"

class Residential : public Building
{

    public:
        Residential(string type);
        virtual bool addOccupant(Citizen *c)=0;
        virtual void demolish() = 0;
        virtual bool clean() = 0;
        virtual bool useShower() = 0;
        virtual bool useToilet() = 0;
        virtual bool useStove() = 0;
        virtual void goToWork()=0;
        virtual Building *clone() = 0;
        virtual bool isOccupied()=0;
};
#endif
