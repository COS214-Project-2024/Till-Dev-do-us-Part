#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H
#include "BuildingFactory.h"
#include "Residential.h"

class ResidentialFactory: public BuildingFactory{

public:
    ResidentialFactory();
    Building* build();
}
#endif