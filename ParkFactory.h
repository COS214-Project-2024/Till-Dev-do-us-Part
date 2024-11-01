#ifndef PARKFACTORY_H
#define PARKFACTORY_H
#include "BuildingFactory.h"
#include "Park.h"

class ParkFactory: public BuildingFactory{

    public:
        ParkFactory();
        Building* build();
};
#endif