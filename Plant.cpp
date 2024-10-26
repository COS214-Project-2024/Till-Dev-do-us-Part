#include "Plant.h"

Plant::Plant():Industrial("Plant"){

}

Plant::~Plant()
{
    for (int i = 0; i < buildings.size(); ++i)
    {
        delete buildings.at(i);
        buildings[i] = nullptr;
    }

    buildings.clear();
}

bool Plant::addBuilding(Industrial *building)
{
    if(building != nullptr && buildings.size() < capacity)
    {
        buildings.push_back(building);
        return true;
    }
    return false;
}

void Plant::demolish()
{
    // this->~Plant();
}

bool Plant::clean()
{
    for (int i = 0; i < buildings.size(); i++)
    {
        if (!buildings[i]->clean())
        {
            return false;
        }
    }
    return true;
}

bool Plant::addOccupant(Citizen *c, string type)
{
    //TODO if type == House, then check that occupants.size == 0. If so, add
    if (c != nullptr)
    {
        for (vector<Industrial*>::iterator it = buildings.begin(); it!= buildings.end(); it++)
        {
            if((*it)->getType() == type && (*it)->addOccupant(c)){
                return true;
            }
        }
        
    }

    return false;
}