#ifndef TOWNHOUSEFACTORY_H
#define TOWNHOUSEFACTORY_H
#include "BuildingFactory.h"
#include "Townhouse.h"

class TownhouseFactory: public BuildingFactory{

    public:
        TownhouseFactory();
        Building* build();
};
#endif