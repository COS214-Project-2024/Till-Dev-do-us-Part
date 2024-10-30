#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H
#include "Residential.h"

class Townhouse : public Residential
{
    private:
        vector<Citizen *> occupants;
    public:
        Townhouse();
        ~Townhouse();
        virtual void demolish();
        virtual bool useShower();
        virtual bool useToilet();
        virtual bool useStove();
        virtual bool clean();
        bool addOccupant(Citizen *c);
        virtual Building* clone();
        bool removeOccupant(Citizen *c);
        virtual void goToWork();
        virtual bool isOccupied();
};
#endif
