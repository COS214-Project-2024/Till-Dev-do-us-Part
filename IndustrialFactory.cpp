#include "IndustrialFactory.h"

IndustrialFactory:: IndustrialFactory()
{
    building= new Industrial();
}

Building* IndustrialFactory:: build()
{
        if (building!=nullptr){
        return building-> clone();

    }
}
