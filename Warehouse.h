#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "Industrial.h"

class Warehouse : public Industrial
{
    private:
        vector<Citizen*> occupants;

    public:
        Warehouse();
        ~Warehouse();
        virtual bool addOccupant(Citizen *c); // inherited from Building, hence this class is abstract
        virtual void demolish();              // inherited from Building, hence this class is abstract
        virtual bool clean();                 // inherited from Building, hence this class is abstract
};
#endif
