#ifndef FACTORYFACTORY_H
#define FACTORYFACTORY_H
#include "BuildingFactory.h"
#include "Factory.h"

class FactoryFactory: public BuildingFactory{

    public:
        FactoryFactory();
        Building* build();
};
#endif