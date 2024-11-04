#include "CBD.h"

CBD::CBD() : Commercial("CBD")
{
    area = 50000;
    capacity = 50;
    noBuildings = 0;
    value = 12000;
}

CBD::~CBD()
{
    delete this->state;
    state = nullptr;
    demolish();
    cout << "Destroyed the CBD\n";
}

void CBD::loadElectricity(float units)
{

    for (vector<Building *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        (*it)->requestElectricity(units);
        electricityUnits += units;
    }
}

void CBD::loadWater(float units)
{
    for (vector<Building *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        (*it)->requestWater(units);
        waterUnits += units;
    }
}

bool CBD::useElectricity(float units)
{
    if (this->state->canUseElectricity())
    {
        electricityUnits = 0;
        bool usedAll = true;
        for (vector<Building *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if (!(*it)->useElectricity(units))
            {
                usedAll = false;
            }
            electricityUnits += (*it)->getElectricity();
        }
        if (!usedAll)
            cout << "Could not use " << units << " of electricity in all the buildings\n";
        else
            cout << "Used " << units << " of electricity in all the buildings\n";

        return usedAll;
    }
    cout << "The CBD is in the " << this->state->getName() << " and cannot use electricity on any buildings" << endl;
    return false;
}

bool CBD::useWater(float units)
{
    if (this->state->canUseWater())
    {
        this->waterUnits = 0;
        bool usedAll = true;
        for (vector<Building *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if (!(*it)->useWater(units))
            {
                usedAll = false;
            }
            waterUnits += (*it)->getWater();
        }

        if (!usedAll)
            cout << "Could not use " << units << " units of water in all the buildings\n";
        else
            cout << "Used " << units << " units of water in all the buildings\n";

        return usedAll;
    }

    cout << "The CBD is in the " << this->state->getName() << " and cannot use water on any buildings" << endl;
    return false;
}

float CBD::getPrice()
{
    return value;
}

string CBD::getType()
{
    return type;
}

void CBD::demolish()
{
    cout << "Demolishing all the buildings in the CBD\n";
    for (vector<Building *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        value -= (*it)->getValue();
        waterUnits -= (*it)->getWater();
        electricityUnits -= (*it)->getElectricity();
        delete (*it);
        (*it) = nullptr;
        noBuildings--;
    }

    cout << "Demolished  all the buildings in the CBD\n";
}

bool CBD::clean()
{
    if (state->canUseElectricity() && state->canUseWater())
    {
        cleanliness = 0;
        waterUnits = 0;
        electricityUnits = 0;
        bool usedAll = true;
        for (vector<Building *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if (!(*it)->clean())
            {
                usedAll = false;
            }
            cleanliness += (*it)->getCleanliness();
            waterUnits += (*it)->getWater();
            electricityUnits += (*it)->getElectricity();
        }

        if (!usedAll)
            cout << "Could not clean all the buildings\n";
        else
            cout << "Cleaned all the buildings\n";

        cleanliness /= buildings.size();
        return usedAll;
    }

    cout << "The CBD is in the " << this->state->getName() << " and cannot use water or electricity on any buildings" << endl;
    return false;
}

bool CBD::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        for (vector<Building *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if ((*it)->addOccupant(c))
            {
                return true;
            }
        }
    }

    return false;
}

int CBD::getNoBuildings()
{
    return noBuildings;
}

bool CBD::addBuilding(Building *building)
{
    if (building != nullptr)
    {
        if (building->getType() == "Mall")
        {
            int mallBuildings = ((Mall *)building)->getNoBuildings();
            if (mallBuildings + noBuildings <= capacity)
            {
                buildings.push_back(building);
                noBuildings += mallBuildings;
                value += building->getValue();
                waterUnits += building->getWater();
                electricityUnits += building->getElectricity();
                cout << "Mall added to the CBD" << endl;
                return true;
            }
            else
            {
                cout << "Mall could not be added to the CBD" << endl;
                return false;
            }
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
                // cout << "Building added to the CBD" << endl;
                return true;
            }
            else
            {
                cout << "Building could not be added to the CBD" << endl;
                return false;
            }
        }
    }

    cout << "Building is non-existent" << endl;
    return false;
}

bool CBD::removeBuilding(Building *building)
{
    vector<Building *>::iterator first = buildings.begin();
    vector<Building *>::iterator last = buildings.end();

    vector<Building *>::iterator it = find(first, last, building);
    if (it != last)
    {

        buildings.erase(it);
        value -= building->getValue();
        waterUnits -= building->getWater();
        electricityUnits -= building->getElectricity();
        cleanliness = (cleanliness - building->getCleanliness()) / noBuildings;
        delete building;
        building = nullptr;
        noBuildings--;
        cout << "Building removed from the CBD" << endl;
        return true;
    }

    cout << "Building not in the CBD" << endl;
    return false;
}

bool CBD::removeOccupant(Citizen *c)
{
    for (vector<Building *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if ((*it)->removeOccupant(c))
        {
            cout << "Citizen removed\n";
            return true;
        }
    }

    cout << "Citizen was not found in any of the buildings in the CBD\n";
    return false;
}

Building *CBD::clone()
{
    CBD *newBuilding = new CBD();
    newBuilding->area = this->area;
    newBuilding->capacity = this->capacity;
    for (vector<Building *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        newBuilding->addBuilding((Commercial *)(*it)->clone());
    }
    newBuilding->cleanliness = this->getCleanliness();
    newBuilding->electricityUnits = this->getElectricity();
    newBuilding->waterUnits = this->getWater();
    newBuilding->state = this->state->clone();
    return newBuilding;
}

float CBD::getCleanliness()
{
    int accumCleanliness = 0;
    for (vector<Building *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumCleanliness += (*it)->getWater();
    }
    cleanliness = accumCleanliness / buildings.size();
    return cleanliness;
}

float CBD::getWater()
{
    int accumWater = 0;
    for (vector<Building *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumWater += (*it)->getWater();
    }
    waterUnits = accumWater;
    return accumWater;
}

float CBD::getElectricity()
{
    int accumElec = 0;
    for (vector<Building *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumElec += (*it)->getElectricity();
    }
    electricityUnits = accumElec;
    return accumElec;
}

bool CBD::isOccupied()
{
    for (vector<Building *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if ((*it)->isOccupied())
        {
            return false;
        }
    }
    return true;
}