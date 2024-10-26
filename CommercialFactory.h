#ifndef CommercialFactory_H
#define CommercialFactory_H
#include "BuildingFactory.h"
#include "Commercial.h"

class CommercialFactory: public BuildingFactory{

public:
    CommercialFactory();
    Building* build();
}
#endif