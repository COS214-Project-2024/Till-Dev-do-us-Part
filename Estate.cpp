#include "Estate.h"

Estate::Estate():Residential("Estate"){

}

Estate::~Estate()
{
    demolish();
    cout << "Estate demolished" << endl;
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
    cout << "Clearing and demolishing all the buildings in the Plant:" << endl;
    for (int i = 0; i < buildings.size(); ++i)
    {
        delete buildings.at(i);
        buildings[i] = nullptr;
    }
    buildings.clear();
    cout << "All buildings in the plant cleared" << endl;
}

bool Estate::useShower()
{
    bool usedAll = true;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if (!(*it)->useShower())
        {
            usedAll = false;
        }
    }

    if (!usedAll)
    {
        cout << "Could not use all showers" << endl;
        return false;
    }

    cout << "Used all showers in the Estate" << endl;
    return true;
}

bool Estate::useToilet()
{
    bool usedAll = true;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if (!(*it)->useToilet())
        {
            usedAll = false;
        }
    }

    if (!usedAll)
    {
        cout << "Could not use all toilets" << endl;
        return false;
    }

    cout << "Used all toilets in the Estate" << endl;
    return true;
}

bool Estate::useStove()
{
    bool usedAll = true;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if (!(*it)->useStove())
        {
            usedAll = false;
        }
    }

    if (!usedAll)
    {
        cout << "Could not use all stoves" << endl;
        return false;
    }

    cout << "Used all stoves in the Estate" << endl;
    return true;
}

Building* Estate::clone(){

}///Added by Karabo

bool Estate::clean()
{
    bool cleanedAll=true;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if (!(*it)->clean())
        {
            cleanedAll = false;
        }
    }

    if (!cleanedAll)
    {
        cout << "Could not clean all buildings " << endl;
        return false;
    }
    cout << "Cleaned all buildings in the Plant" << endl;
    return true;
}

bool Estate::addOccupant(Citizen *c)
{
    //TODO if type == House, then check that occupants.size == 0. If so, add
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