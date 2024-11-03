#include "IndustrialSite.h"

IndustrialSite::IndustrialSite() : Industrial("IndustrialSite")
{
    area = 10000;
    capacity = 50;
    noBuildings = 0;
    value = 12000;
}

void IndustrialSite::loadElectricity(float units)
{

    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        (*it)->requestElectricity(units);
        electricityUnits += units;
    }
}

void IndustrialSite::loadWater(float units)
{
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        (*it)->requestWater(units);
        waterUnits += units;
    }
}

bool IndustrialSite::useElectricity(float units)
{
    if (this->state->canUseElectricity())
    {
        electricityUnits = 0;
        bool usedAll = true;
        for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
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
    cout << "The Industrial Site is in the " << this->state->getName() << " and cannot use electricity on any buildings" << endl;
    return false;
}

bool IndustrialSite::useWater(float units)
{
    if (this->state->canUseWater())
    {
        this->waterUnits = 0;
        bool usedAll = true;
        for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
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

    cout << "The Industrial Site is in the " << this->state->getName() << " and cannot use water on any buildings" << endl;
    return false;
}

float IndustrialSite::getPrice()
{
    return value;
}

string IndustrialSite::getType()
{
    return type;
}

void IndustrialSite::demolish()
{
    cout << "Demolishing all the buildings in the IndustrialSite\n";
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        value -= (*it)->getValue();
        waterUnits -= (*it)->getWater();
        electricityUnits -= (*it)->getElectricity();
        delete (*it);
        (*it) = nullptr;
        noBuildings--;
    }

    cout << "Demolished  all the buildings in the IndustrialSite\n";
}

bool IndustrialSite::clean()
{
    if (state->canUseElectricity() && state->canUseWater())
    {
        cleanliness = 0;
        waterUnits = 0;
        electricityUnits = 0;
        bool usedAll = true;
        for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
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

    cout << "The Suburb is in the " << this->state->getName() << " and cannot use water or electricity on any buildings" << endl;
    return false;
}

bool IndustrialSite::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if ((*it)->addOccupant(c))
            {
                return true;
            }
        }
    }

    return false;
}

IndustrialSite::~IndustrialSite()
{
    demolish();
    cout << "Destroyed the IndustrialSite\n";
}

bool IndustrialSite::addBuilding(Industrial *building)
{
    if (building != nullptr)
    {
        if (building->getType() == "Plant")
        {
            int plantBuildings = ((Plant *)building)->getNoBuildings();
            if (plantBuildings + noBuildings <= capacity)
            {
                buildings.push_back(building);
                noBuildings += plantBuildings;
                value += building->getValue();
                waterUnits += building->getWater();
                electricityUnits += building->getElectricity();
                cout << "Plant added to the Industrial Site" << endl;
                return true;
            }
            else
            {
                cout << "Plant could not be added to the Industrial Site" << endl;
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
                cout << "Building added to the Industrial Site" << endl;
                return true;
            }
            else
            {
                cout << "Building could not be added to the Industrial Site" << endl;
                return false;
            }
        }
    }

    cout << "Building is non-existent" << endl;
    return false;
}

bool IndustrialSite::removeBuilding(Industrial *building)
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
        delete building;
        building = nullptr;
        noBuildings--;
        cout << "Building removed from the Industrial Site" << endl;
        return true;
    }

    cout << "Building not in the Industrial Site" << endl;
    return false;
}

bool IndustrialSite::removeOccupant(Citizen *c)
{
    for (vector<Industrial *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if ((*it)->removeOccupant(c))
        {
            cout << "Citizen removed\n";
            return true;
        }
    }

    cout << "Citizen was not found in any of the buildings in the IndustrialSite\n";
    return false;
}

Building *IndustrialSite::clone()
{
    IndustrialSite *newBuilding = new IndustrialSite();

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

float IndustrialSite::getCleanliness()
{
    int accumCleanliness = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumCleanliness += (*it)->getWater();
    }
    cleanliness = accumCleanliness / buildings.size();
    return cleanliness;
}

float IndustrialSite::getWater()
{
    int accumWater = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumWater += (*it)->getWater();
    }
    waterUnits = accumWater;
    return accumWater;
}

float IndustrialSite::getElectricity()
{
    int accumElec = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumElec += (*it)->getElectricity();
    }
    electricityUnits = accumElec;
    return accumElec;
}

int IndustrialSite::getNoBuildings()
{
    return noBuildings;
}

bool IndustrialSite::isOccupied()
{
    for (vector<Industrial *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if ((*it)->isOccupied())
        {
            return false;
        }
    }

    return true;
}