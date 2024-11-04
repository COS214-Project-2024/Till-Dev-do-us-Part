#include "OfficeFactory.h"

OfficeFactory:: OfficeFactory()
{
    building = new Office();
}

Building* OfficeFactory:: build()
{
    if (building!=nullptr){
        return building-> clone();

    }
}
