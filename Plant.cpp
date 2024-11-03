#include "Plant.h"

Plant::Plant():Industrial("Plant"){
    area = 4000;
    capacity = 15;
    value=100000;
    noBuildings = 0;
    cout << "Plant created" << endl;
}

Plant::~Plant()
{
    demolish();
    cout << "Plant demolished" << endl;
}

bool Plant::addBuilding(Industrial *building)
{
    if (building != nullptr)
    {
        if (building->getType() == "Plant")
        {
            cout << "Cannot add a Plant to a Plant" << endl;
            return false;
        }
        else
        {
            if (noBuildings + 1 <= capacity)
            {
                buildings.push_back(building);
                noBuildings++;
                value += building->getValue();
                waterUnits += building->getWater();
                electricityUnits += building->getElectricity();
                cleanliness = (cleanliness + building->getCleanliness()) / noBuildings;
                cout << "Building added to the Mall" << endl;
                return true;
            }
            else
            {
                cout << "Could not build, not enough land/space" << endl;
                return false;
            }
        }
    }
    cout << "Cannot add non-existent building to the Mall" << endl;
    return false;
}

bool Plant::removeBuilding(Industrial *building)
{
    vector<Industrial *>::iterator first = buildings.begin();
    vector<Industrial *>::iterator last = buildings.end();

    vector<Industrial *>::iterator it = find(first, last, building);
    if (it != last)
    {

        buildings.erase(it);
        value -= building->getValue();
        waterUnits -= building->getWater();
        electricityUnits -= building->getElectricity();
        cleanliness = (cleanliness - building->getCleanliness()) / noBuildings;
        building = nullptr;
        noBuildings--;
        cout << "Building removed from the Estate" << endl;
        return true;
    }

    cout << "Building not in the Estate" << endl;
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
    cout << "Demolished all buildings in the Plant" << endl;
}

bool Plant::clean()
{
    bool cleanedAll = true;
    for (vector<Industrial*>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if (!(*it)->clean())
        {
            cleanedAll = false;
        }
    }

    if(!cleanedAll){
        cout << "Could not clean all buildings "<< endl;
        return false;
    }

    cout << "Cleaned all buildings in the Plant" << endl;
    return true;
}

bool Plant::addOccupant(Citizen *c)
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

        cout << "Citizen could not be added to Plant, all bulidings at capacity\n";
        return false;
    }

    cout << "All "<< type << " buildings in the Plant are at capacity"<< endl;
    return false;
}

bool Plant::removeOccupant(Citizen *c)
{
    for (vector<Industrial *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if ((*it)->removeOccupant(c))
        {
            cout << "Occupant removed!\n";
            return true;
        }
    }
    cout << "Occupant not found in any of the buildings in the Plant\n";
    return false;
}

Building *Plant::clone()
{
    Plant *newBuilding = new Plant();
    newBuilding->area = this->area;
    newBuilding->capacity = this->capacity;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        newBuilding->addBuilding((Industrial *)(*it)->clone());
    }
    newBuilding->cleanliness = this->getCleanliness();
    newBuilding->electricityUnits = this->getElectricity();
    newBuilding->waterUnits = this->getWater();
    newBuilding->state = this->state->clone();
    return newBuilding;
}

float Plant::getCleanliness()
{
    int count = 0;
    int accumCleanliness = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumCleanliness += (*it)->getCleanliness();
        count++;
    }
    cleanliness = accumCleanliness / count;
    return cleanliness;
}

float Plant::getWater()
{
    int accumWater = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumWater += (*it)->getWater();
    }
    waterUnits = accumWater;
    return waterUnits;
}

float Plant::getElectricity()
{
    int accumElec = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumElec += (*it)->getElectricity();
    }
    electricityUnits = accumElec;
    return electricityUnits;
}

bool Plant::isOccupied()
{
    for (vector<Industrial *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if (!(*it)->isOccupied())
        {
            return false;
        }
    }

    return true;
}

int Plant:: getNoBuildings(){
    return noBuildings;
}