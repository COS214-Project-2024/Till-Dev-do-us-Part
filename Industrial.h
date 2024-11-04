#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H
#include "Building.h"

class Industrial : public Building
{
    public:
        Industrial(string type);
        virtual bool addOccupant(Citizen *c) = 0; // inherited from Building, hence this class is abstract
        virtual void demolish() = 0;              // inherited from Building, hence this class is abstract
        virtual bool clean() = 0;                 // inherited from Building, hence this class is abstract

};
#endif
