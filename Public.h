#ifndef PUBLIC_H
#define PUBLIC_H
#include "Building.h"

class Public : public Building
{
    public:
        Public(string type);
        virtual bool addOccupant(Citizen *c) = 0;
        virtual void demolish() = 0;             
        virtual bool clean() = 0;
        
};
#endif

