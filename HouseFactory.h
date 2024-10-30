#ifndef HOUSEFACTORY_H
#define HOUSEFACTORY_H
#include "BuildingFactory.h"
#include "House.h"

class HouseFactory: public BuildingFactory{

    public:
        HouseFactory();
        Building* build();
};
#endif