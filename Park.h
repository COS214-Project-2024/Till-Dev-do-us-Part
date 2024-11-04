
#ifndef PARK_H
#define PARK_H
#include "Landmark.h"
class Citizen;

class Park : public Landmark
{
    public:
        Park();
        ~Park();
        virtual bool addOccupant(Citizen *c);
        virtual void demolish();
        virtual bool clean();
        virtual bool removeOccupant(Citizen *c);
        virtual Building *clone();
};
#endif
