#ifndef MONUMENT_H
#define MONUMENT_H
#include "Landmark.h"
class Citizen;

class Monument : public Landmark
{
    public:
        Monument();
        // virtual void demolish();
        virtual bool clean();
        // virtual bool addOccupant(Citizen *c);
};
#endif
