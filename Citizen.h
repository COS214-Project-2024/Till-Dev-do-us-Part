#ifndef CITIZEN_H
#define CITIZEN_H
// #include "House.h"
// #include "Townhouse.h"
// #include "Estate.h"
// #include "Residential.h"
class Building;
class Residential;
class Citizen{
    protected:
        Residential *building;

    public:
        virtual void addHome(Residential*b);
        virtual void goToWork();
};

#endif