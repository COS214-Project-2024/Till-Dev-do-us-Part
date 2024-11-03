#include "HouseFactory.h"

HouseFactory:: HouseFactory()
{
    building = new House();
}

Building* HouseFactory:: build()
{
    return building-> clone();
}