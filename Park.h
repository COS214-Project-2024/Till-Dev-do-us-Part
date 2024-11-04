#ifndef PARK_H
#define PARK_H
#include "Landmark.h"
class Citizen;

class Park : public Landmark
{
    public:
        Park();
        // virtual void demolish();
        virtual bool clean() = 0; // inherited from Building, hence this class is abstract
        // virtual bool addOccupant(Citizen *c) = 0;
};
#endif
