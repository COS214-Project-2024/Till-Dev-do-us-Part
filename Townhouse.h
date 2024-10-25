#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H
#include "Residential.h"

class Townhouse : public Residential
{
    private:
        /* data */
    public:
        Townhouse(/* args */);
        ~Townhouse();
        virtual void demolish();  // inherited from Building, hence this class is abstract
        virtual bool useShower(); //
        virtual bool useToilet(); // why boolean, because when there isnt enough water/electricity it must affect the citizen
        virtual bool useStove();  // why boolean, because when there isnt enough water/electricity it must affect the citizen
        virtual bool clean();
};
#endif
