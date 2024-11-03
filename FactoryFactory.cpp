#include "FactoryFactory.h"

FactoryFactory:: FactoryFactory()
{
    building = new Factory();
}

Building* FactoryFactory:: build()
{
    return building-> clone();
}