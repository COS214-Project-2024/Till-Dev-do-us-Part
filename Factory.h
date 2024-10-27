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
        virtual bool addOccupant(Citizen *c); // inherited from Building, hence this class is abstract
        virtual void demolish();              // inherited from Building, hence this class is abstract
        virtual bool clean();                 // inherited from Building, hence this class is abstract
};
#endif
