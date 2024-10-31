#ifndef HOUSE_H
#define HOUSE_H
#include "Residential.h"

class House : public Residential
{
    private:
        /* data */
        vector<Citizen *> occupants;

    public:
        House();
        ~House();
        virtual void demolish(); //inherited from Building, hence this class is abstract
        virtual bool useShower(); //
        virtual bool useToilet(); // why boolean, because when there isnt enough water/electricity it must affect the citizen
        virtual bool useStove();  // why boolean, because when there isnt enough water/electricity it must affect the citizen
        virtual bool clean();
        virtual Building* clone();
        virtual bool addOccupant(Citizen *c);
};
#endif
