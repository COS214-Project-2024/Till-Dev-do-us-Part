#ifndef ESTATE_H
#define ESTATE_H
#include "Residential.h"

class Estate : public Residential
{
    private:
        vector<Residential *> buildings;

    public:
        Estate();
        ~Estate();
        virtual void demolish();
        virtual bool useShower();
        virtual bool useToilet();
        virtual bool useStove();
        virtual bool clean();
        bool addOccupant(Citizen *c);
        bool addHouse(Residential *); // if capacity is reached, return false
    
};
#endif
