#include "Suburb.h"

Suburb::Suburb() : Residential("Suburb")
{
    area = 50000;
    capacity = 50;
    noBuildings = 0;
    value = 12000;
}

void Suburb::loadElectricity(float units)
{

    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        (*it)->requestElectricity(units);
        electricityUnits += units;
    }
}

void Suburb::loadWater(float units)
{
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        (*it)->requestWater(units);
        waterUnits += units;
    }
}

float Suburb::getPrice()
{
    return value;
}

string Suburb::getType()
{
    return type;
}

void Suburb::demolish()
{
    cout << "Demolishing all the buildings in the suburb\n";
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        delete (*it);
        (*it) = nullptr;
    }

    cout << "Demolished  all the buildings in the suburb\n";
}

bool Suburb::clean()
{
    if (state->canUseElectricity() && state->canUseWater())
    {
        cleanliness = 0;
        waterUnits = 0;
        electricityUnits = 0;
        bool usedAll = true;
        for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
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

bool Suburb::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if ((*it)->addOccupant(c))
            {
                return true;
            }
        }
    }

    return false;
}

Suburb::~Suburb()
{
    demolish();
    cout << "Destroyed the suburb\n";
}

bool Suburb::addBuilding(Residential *building)
{
    if (building != nullptr)
    {
        if (building->getType() == "Estate")
        {
            int estateBuildings = ((Estate *)building)->getNoBuildings();
            if (estateBuildings + noBuildings <= capacity)
            {
                buildings.push_back(building);
                noBuildings += estateBuildings;
                value += building->getValue();
                waterUnits += building->getWater();
                electricityUnits += building->getElectricity();
                cleanliness = (cleanliness + building->getCleanliness()) / noBuildings;
                cout << "Estate added to the Suburb" << endl;
                return true;
            }
            else
            {
                cout << "Estate could not be added to the Suburb" << endl;
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
                // cout << "Building added to the Suburb" << endl;
                return true;
            }
            else
            {
                // cout << "Building could not be added to the Suburb" << endl;
                return false;
            }
        }
    }

    cout << "Building is non-existent" << endl;
    return false;
}

bool Suburb::removeBuilding(Residential *building)
{
    vector<Residential *>::iterator first = buildings.begin();
    vector<Residential *>::iterator last = buildings.end();

    vector<Residential *>::iterator it = find(first, last, building);
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

bool Suburb::removeOccupant(Citizen *c)
{
    for (vector<Residential *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if ((*it)->removeOccupant(c))
        {
            cout << "Citizen removed\n";
            return true;
        }
    }

    cout << "Citizen was not found in any of the buildings in the suburb\n";
    return false;
}

bool Suburb::useElectricity(float units)
{
    if (this->state->canUseElectricity())
    {
        electricityUnits = 0;
        bool usedAll = true;
        for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
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
    cout << "The Suburb is in the " << this->state->getName() << " and cannot use electricity on any buildings" << endl;
    return false;
}

bool Suburb::useWater(float units)
{
    if (this->state->canUseWater())
    {
        waterUnits = 0;
        bool usedAll = true;
        for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
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

    cout << "The Suburb is in the " << this->state->getName() << " and cannot use water on any buildings" << endl;
    return false;
}

bool Suburb::useShower()
{
    if (state->canUseElectricity() && state->canUseWater())
    {
        cleanliness = 0;
        waterUnits = 0;
        electricityUnits = 0;
        bool usedAll = true;
        for (vector<Residential *>::iterator it = buildings.begin(); it < buildings.end(); it++)
        {
            if (!(*it)->useShower())
            {
                usedAll = false;
            }
            cleanliness += (*it)->getCleanliness();
            waterUnits += (*it)->getWater();
            electricityUnits += (*it)->getElectricity();
        }

        cleanliness /= buildings.size();

        if (usedAll)
        {
            cout << "Used all Showers in the Suburb\n";
        }
        else
        {
            cout << "Could not used all Showers in the Suburb\n";
        }

        return usedAll;
    }

    cout << "The Suburb is in the " << this->state->getName() << " and cannot showers on any buildings" << endl;
    return false;
}

bool Suburb::useToilet()
{
    if (state->canUseWater() && state->canUseElectricity())
    {
        cleanliness = 0;
        waterUnits = 0;
        electricityUnits = 0;
        bool usedAll = true;
        for (vector<Residential *>::iterator it = buildings.begin(); it < buildings.end(); it++)
        {
            if (!(*it)->useToilet())
            {
                usedAll = false;
            }
            cleanliness += (*it)->getCleanliness();
            waterUnits += (*it)->getWater();
            electricityUnits += (*it)->getElectricity();
        }

        cleanliness /= buildings.size();

        if (usedAll)
        {
            cout << "Used all Toilets in the Suburb\n";
        }
        else
        {
            cout << "Could not used all Toilets in the Suburb\n";
        }
        return usedAll;
    }

    cout << "The Suburb is in the " << this->state->getName() << " and cannot use toilets on any buildings" << endl;
    return false;
}

bool Suburb::useStove()
{
    if (this->state->canUseElectricity())
    {
        cleanliness = 0;
        waterUnits = 0;
        electricityUnits = 0;
        bool usedAll = true;
        for (vector<Residential *>::iterator it = buildings.begin(); it < buildings.end(); it++)
        {
            if (!(*it)->useStove())
            {
                usedAll = false;
            }
            cleanliness += (*it)->getCleanliness();
            waterUnits += (*it)->getWater();
            electricityUnits += (*it)->getElectricity();
        }
        cleanliness /= buildings.size();

        if (usedAll)
        {
            cout << "Used all Stoves in the Suburb\n";
        }
        else
        {
            cout << "Could not used all Stoves in the Suburb\n";
        }
        return usedAll;
    }

    cout << "The Suburb is in the " << this->state->getName() << " and cannot use stoves on any buildings" << endl;
    return false;
}

void Suburb::goToWork()
{
    cleanliness = 0;
    waterUnits = 0;
    electricityUnits = 0;
    for (vector<Residential *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        (*it)->goToWork();
        cleanliness += (*it)->getCleanliness();
        waterUnits += (*it)->getWater();
        electricityUnits += (*it)->getElectricity();
    }

    cleanliness /= buildings.size();
    cout << "Took all citizens in the Suburb to work\n";
}

bool Suburb::isOccupied()
{
    for (vector<Residential *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if ((*it)->isOccupied())
        {
            return false;
        }
    }

    return true;
}
Building *Suburb::clone()
{
    Suburb *newBuilding = new Suburb();
    newBuilding->cleanliness = this->getCleanliness();
    newBuilding->electricityUnits = this->getElectricity();
    newBuilding->waterUnits = this->getWater();
    newBuilding->area = this->area;
    newBuilding->capacity = this->capacity;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        newBuilding->addBuilding((Residential *)(*it)->clone());
    }
    newBuilding->state = this->state->clone();
    return newBuilding;
}

float Suburb::getCleanliness()
{
    int accumCleanliness = 0;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumCleanliness += (*it)->getWater();
    }
    cleanliness = accumCleanliness / buildings.size();
    return cleanliness;
}

float Suburb::getWater()
{
    int accumWater = 0;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumWater += (*it)->getWater();
    }
    waterUnits = accumWater;
    return accumWater;
}

float Suburb::getElectricity()
{
    int accumElec = 0;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumElec += (*it)->getElectricity();
    }
    electricityUnits = accumElec;
    return accumElec;
}

int Suburb::getNoBuildings()
{
    return noBuildings;
}
