#ifndef FACTORY_H
#define FACTORY_H
#include "Industrial.h"

class Factory : public Industrial
{
    private:
        vector<Citizen*> occupants;
    public:
        Factory();
        ~Factory();
        virtual bool addOccupant(Citizen *c);
        virtual bool removeOccupant(Citizen *c);
        virtual void demolish();
        virtual bool clean();
        virtual Building *clone();
        virtual bool isOccupied();
};
#endif
