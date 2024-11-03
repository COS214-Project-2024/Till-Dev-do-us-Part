#ifndef MONUMENTFACTORY_H
#define MONUMENTFACTORY_H
#include "BuildingFactory.h"
#include "Monument.h"

class MonumentFactory: public BuildingFactory{

    public:
        MonumentFactory();
        Building* build();
};
#endif