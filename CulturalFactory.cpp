#include "CulturalFactory.h"

CulturalFactory:: CulturalFactory()
{
    building = new CulturalCenter();
}

Building* CulturalFactory:: build()
{
    return building-> clone();
}