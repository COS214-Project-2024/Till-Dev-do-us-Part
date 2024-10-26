#include "Estate.h"

Estate::Estate():Residential("Estate"){

}

Estate::~Estate()
{
    for (int i = 0; i < buildings.size(); ++i)
    {
        delete buildings.at(i);
        buildings[i] = nullptr;
    }

    buildings.clear();
}

bool Estate::addHouse(Residential *building)
{
    if(building != nullptr && buildings.size() < capacity)
    {
        buildings.push_back(building);
        return true;
    }
    return false;
}

void Estate::demolish()
{
    // this->~Estate();
}

bool Estate::useShower()
{
    for (int i = 0; i < buildings.size(); i++)
    {
        if(!buildings[i]->useShower()){
            return false;
        }
    }
    return true;
}

bool Estate::useToilet()
{
    for (int i = 0; i < buildings.size(); i++)
    {
        if (!buildings[i]->useToilet())
        {
            return false;
        }
    }
    return true;
}

bool Estate::useStove()
{
    for (int i = 0; i < buildings.size(); i++)
    {
        if (!buildings[i]->useStove())
        {
            return false;
        }
    }
    return true;
}

bool Estate::clean()
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

bool Estate::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        for (vector<Residential*>::iterator it = buildings.begin(); it!= buildings.end(); it++)
        {
            if((*it)->addOccupant(c)){
                return true;
            }
        }
        
    }

    return false;
}