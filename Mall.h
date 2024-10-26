#ifndef MALL_H
#define MALL_H
#include "Commercial.h"

class Mall: public Commercial
{
    private:
        vector<Commercial*> stores;
    public:
        Mall();
        ~Mall();
        bool addStore(Commercial*); //if capacity is reached, return false
        virtual void demolish();
        virtual bool clean();
        virtual bool addOccupant(Citizen *c);
};
#endif

