#include "Townhouse.h"

Townhouse::Townhouse():Residential("Townhouse"){
    value = 80000;
    area = 200;
    capacity = 3;
}

Townhouse ::~Townhouse(){
    demolish();
    cout << "Townhouse demolished!" << endl;
}

void Townhouse::demolish()
{
    cout << "Removing everyone from the Townhouse" << endl;
    occupants.clear();
}

bool Townhouse::useShower()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(100) && useElectricity(50))
        {
            cout << "Townhouse used shower.";
            if (cleanliness - 15 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
                cout << "Townhouse is now in Dilapidated state:\n";
                cout << "Cleanliness: " << cleanliness << "\n";
                cout << "Electricity: " << electricityUnits << "\n";
                cout << "Water: " << waterUnits << "\n";
            }
            else{
                cleanliness -= 15;
            }
            return true;
        }
        cout << "Not enough water or electricity to use shower:" << endl;
        cout << "Required water to shower: 100" << endl;
        cout << "Required electricity to shower: 50" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "Townhouse is in " << this->state->getName() << " and cannot use shower" << endl;
    return false;
}

bool Townhouse::useToilet()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(13) && useElectricity(3))
        {
            if (cleanliness - 10 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
            }
            else{
                cleanliness -= 10;
            }
            cout << "Townhouse used toilet.";
            return true;
        }
        cout << "Not enough water to use toilet:" << endl;
        cout << "Required electricity for toilet: 3" << endl;
        cout << "Required water for toilet: 13" << endl;
        cout << "Current water: " << waterUnits << endl;
        return false;
    }

    cout << "Townhouse is in " << this->state->getName() << " and cannot use Toilet" << endl;
    return false;
}

bool Townhouse::useStove()
{
    if (this->state->canUseElectricity())
    {
        if (useElectricity(58))
        {
            if (cleanliness - 15 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
            }
            else{
                cleanliness -= 15;
            }
            cout << "Used stove.";
            return true;
        }
        cout << "Not enough electricity to use stove:" << endl;
        cout << "Required electricity for stove: 58" << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "Townhouse is in " << this->state->getName() << " and use stove" << endl;
    return false;
}

bool Townhouse::clean()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(300) && useElectricity(70))
        {
            if (cleanliness + 30 >= 100)
            {
                cleanliness = 100;
            }
            else
            {
                if(cleanliness <=0 && cleanliness+30 >=0 && waterUnits > 0 && electricityUnits >0){
                    delete state;
                    state = new CompleteState();
                }
                cleanliness += 30;
            }
            cout << "Townhouse cleaned.";
            return true;
        }
        cout << "Not enough water or electricity to clean the Townhouse:" << endl;
        cout << "Required water to clean: 300" << endl;
        cout << "Required electricity to clean: 70" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "Townhouse is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

bool Townhouse::addOccupant(Citizen *c)
{
    if (c != nullptr && occupants.size() < capacity)
    {
        occupants.push_back(c);
        cout << "Occupant added to Townhouse" << endl;
        return true;
    }

    return false;
}

bool Townhouse::removeOccupant(Citizen *c)
{
    vector<Citizen *>::iterator first = occupants.begin();
    vector<Citizen *>::iterator last = occupants.end();

    vector<Citizen *>::iterator it = find(first, last, c);
    if (it != last)
    {
        occupants.erase(it);
        cout << "Occupant removed from the Townhouse" << endl;
        return true;
    }
    cout << "Occupant not in the Townhouse" << endl;
    return false;
}

Building *Townhouse::clone()
{
    Townhouse*newHouse = new Townhouse();
    newHouse->cleanliness = this->cleanliness;
    newHouse->electricityUnits = this->electricityUnits;
    newHouse->waterUnits = this->waterUnits;
    newHouse->value = this->value;
    newHouse->area = this->area;
    newHouse->capacity = this->capacity;

    return newHouse;
}

void Townhouse::goToWork()
{
    for (vector<Citizen *>::iterator it = occupants.begin(); it < occupants.end(); it++)
    {
        (*it)->goToWork();
    }
}

bool Townhouse::isOccupied()
{
    return occupants.size() > 0;
}