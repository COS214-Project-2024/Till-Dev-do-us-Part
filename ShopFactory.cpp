#include "ShopFactory.h"

ShopFactory:: ShopFactory()
{
    building= new Shop();
}

Building* ShopFactory:: build()
{
    if (building!=nullptr){
        return building-> clone();

    }
}
