#ifndef PARK_H
#define PARK_H
#include "Landmark.h"
class Citizen;

class Park : public Landmark
{
    public:
        Park();
        // virtual void demolish();
        virtual bool clean(); // inherited from Building, hence this class is abstract
        virtual Building* clone();
        // virtual bool addOccupant(Citizen *c) = 0;
};
#endif
