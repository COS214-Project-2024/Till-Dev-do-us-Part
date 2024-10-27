#include "Shop.h"

Shop::Shop():Commercial("Shop"){

}

Shop::~Shop(){
    occupants.clear();
}

void Shop::demolish(){
    //want it to call the destructor
}

bool Shop::clean()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(350) && useElectricity(300))
        {
            cout << "Shop cleaned.";
            return true;
        }
        cout << "Not enough water or electricity to clean the Shop:" << endl;
        cout << "Required water to clean: 350" << endl;
        cout << "Required electricity to clean: 300" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "Shop is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

bool Shop::addOccupant(Citizen *c){
    if (c != nullptr && occupants.size() < capacity)
    {
        occupants.push_back(c);
        return true;
    }

    return false;
}

