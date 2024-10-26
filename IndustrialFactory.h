#ifndef IndustrialFactory_H
#define IndustrialFactory_H
#include "BuildingFactory.h"
#include "Industrial.h"

class IndustrialFactory: public BuildingFactory{

public:
    IndustrialFactory();
    Building* build();
}
#endif