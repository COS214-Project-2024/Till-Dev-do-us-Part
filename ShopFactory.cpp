#include "ShopFactory.h"

ShopFactory:: ShopFactory()
{
    building= new Shop();
}

Building* ShopFactory:: build()
{
    return building-> clone();
}
