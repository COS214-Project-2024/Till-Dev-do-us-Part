#ifndef SHOP_H
#define SHOP_H
#include "Commercial.h"

class Shop : public Commercial
{
    private:
        // vector<Citizen *> occupants;
        Citizen* occupant;
    
    public:
        Shop();
        ~Shop();
        virtual void demolish();
        virtual bool clean();
        virtual bool addOccupant(Citizen *c);
        virtual Building* clone();
};
#endif