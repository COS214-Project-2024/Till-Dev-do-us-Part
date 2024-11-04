#ifndef SHOP_H
#define SHOP_H
#include "Commercial.h"

class Shop : public Commercial
{
    private:
        Citizen * occupants;

    public:
        Shop();
        ~Shop();
        virtual void demolish();
        virtual bool clean();
        virtual bool addOccupant(Citizen *c);
        virtual Building* clone();
};
#endif