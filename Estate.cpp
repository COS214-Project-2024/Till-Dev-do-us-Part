#include "Estate.h"

Estate::Estate():Residential("Estate"){

}

Estate::~Estate()
{
    for (int i = 0; i < houses.size(); ++i)
    {
        delete houses.at(i);
        houses[i] = nullptr;
    }

    houses.clear();
}

bool Estate::addHouse(Residential *building)
{
    if(building != nullptr && houses.size() < capacity)
    {
        houses.push_back(building);
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
    for (int i = 0; i < houses.size(); i++)
    {
        if(!houses[i]->useShower()){
            return false;
        }
    }
    return true;
}

bool Estate::useToilet()
{
    for (int i = 0; i < houses.size(); i++)
    {
        if (!houses[i]->useToilet())
        {
            return false;
        }
    }
    return true;
}

bool Estate::useStove()
{
    for (int i = 0; i < houses.size(); i++)
    {
        if (!houses[i]->useStove())
        {
            return false;
        }
    }
    return true;
}

bool Estate::clean()
{
    for (int i = 0; i < houses.size(); i++)
    {
        if (!houses[i]->clean())
        {
            return false;
        }
    }
    return true;
}
