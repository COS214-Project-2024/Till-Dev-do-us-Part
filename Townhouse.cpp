#include "Townhouse.h"

Townhouse::Townhouse():Residential("Townhouse"){

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
    if (this->state->canUseWater())
    {
        if(useWater(16))
        {
            cout << "Used toilet.";
            return true;
        }
        cout << "Not enough water to use toilet:" << endl;
        cout << "Required water for toilet: 16" << endl;
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
        return true;
    }

    return false;
}