#include "EstateFactory.h"

EstateFactory:: EstateFactory()
{
    building = new Estate();
}

Building* EstateFactory:: build()
{
    return building-> clone();
}