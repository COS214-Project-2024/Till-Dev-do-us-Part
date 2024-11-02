#include "OfficeFactory.h"

OfficeFactory:: OfficeFactory()
{
    building = new Office();
}

Building* OfficeFactory:: build()
{
    return building-> clone();
}