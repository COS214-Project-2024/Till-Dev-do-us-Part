#include "CBDFactory.h"

CBDFactory:: CBDFactory()
{
    building = new CBD();
}

Building* CBDFactory:: build()
{
    return building-> clone();
}