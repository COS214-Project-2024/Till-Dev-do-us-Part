#include "IndustrialFactory.h"

IndustrialFactory:: IndustrialFactory()
{
    building = new IndustrialSite();
}

Building* IndustrialFactory:: build()
{
    return building-> clone();
}