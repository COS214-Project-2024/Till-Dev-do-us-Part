#include "MallFactory.h"

MallFactory:: MallFactory()
{
    building = new Mall();
}

Building* MallFactory:: build()
{
    if (building!=nullptr){
        return building-> clone();

    }
}
