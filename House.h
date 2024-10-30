#ifndef HOUSE_H
#define HOUSE_H
#include "Residential.h"

class House : public Residential
{
    private:
        vector<Citizen *> occupants;

    public:
        House();
        ~House();
        virtual void demolish(); 
        virtual bool useShower();
        virtual bool useToilet();
        virtual bool useStove();
        virtual bool clean();
        virtual bool addOccupant(Citizen *c);
        Building* clone();
        bool removeOccupant(Citizen *c);
        virtual void goToWork();
        virtual bool isOccupied();
};
#endif
