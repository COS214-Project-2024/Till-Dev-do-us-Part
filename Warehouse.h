#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "Industrial.h"

class Warehouse : public Industrial
{
    private:
        vector<Citizen*> occupants;

    public:
        Warehouse();
        virtual ~Warehouse();
        virtual bool addOccupant(Citizen *c);
        virtual bool removeOccupant(Citizen *c);
        virtual void demolish();
        virtual bool clean();
        virtual Building *clone();
        virtual bool isOccupied();
};
#endif
