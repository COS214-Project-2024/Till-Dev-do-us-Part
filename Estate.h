#ifndef ESTATE_H
#define ESTATE_H
#include "Residential.h"

class Estate : public Residential
{
    private:
        vector<Residential *> houses;

    public:
        Estate();
        ~Estate();
        virtual void demolish();
        virtual bool useShower();
        virtual bool useToilet();
        virtual bool useStove();
        virtual bool clean();
        bool addHouse(Residential *); // if capacity is reached, return false
};
#endif
