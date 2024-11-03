#ifndef ESTATEFACTORY_H
#define ESTATEFACTORY_H
#include "BuildingFactory.h"
#include "Estate.h"

class EstateFactory: public BuildingFactory{

    public:
        EstateFactory();
        Building* build();
};
#endif