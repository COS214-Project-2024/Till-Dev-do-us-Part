#ifndef MONUMENT_H
#define MONUMENT_H
#include "Landmark.h"
class Citizen;

class Monument : public Landmark
{
    public:
        Monument();
        ~Monument();
        virtual bool addOccupant(Citizen *c);
        virtual void demolish();
        virtual bool clean();
        virtual bool removeOccupant(Citizen *c);
        virtual Building *clone();
};
#endif