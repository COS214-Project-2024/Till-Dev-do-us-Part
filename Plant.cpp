#include "Plant.h"

Plant::Plant():Industrial("Plant"){
    cout << "Plant created" << endl;
}

Plant::~Plant()
{
    demolish();
    cout << "Plant demolished" << endl;
}

bool Plant::addBuilding(Industrial *building)
{
    if(building != nullptr && buildings.size() < capacity)
    {
        buildings.push_back(building);
        cout << "Building added successfully!" << endl;
        return true;
    }
    cout << "Building could not be added, not Plant at capacity!" << endl;
    return false;
}

void Plant::demolish()
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

bool Plant::clean()
{
    for (vector<Industrial*>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if (!(*it)->clean())
        {
            cout << "Could not clean building " << (*it) << ": Not enough water or electricity for the building" << endl;
            return false;
        }
    }

    cout << "Cleaned all buildings in the Plant" << endl;
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
                cout << "Occupant added to building " << (*it) << endl;
                return true;
            }
        }
        
    }

    cout << "All "<< type << " buildings in the Plant are at capacity"<< endl;
    return false;
}