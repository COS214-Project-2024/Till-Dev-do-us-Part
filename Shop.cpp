#include "Shop.h"

Shop::Shop():Commercial("Shop"){
    area = 200;
    value = 300000;
    capacity = 1;
    occupant= nullptr;
}

Shop::~Shop(){
    delete this->state;
    state = nullptr;
    demolish();
    cout << "Shop demolished!" << endl;
}

void Shop::demolish(){
    cout << "Removing occupant from the Office" << endl;
    occupant = nullptr;
}

bool Shop::clean()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(350) && useElectricity(300))
        {
            cout << "Shop cleaned.";
            if (cleanliness - 10 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
                cout << "Shop is now in Dilapidated state\n";
            }
            else
            {
                cleanliness -= 10;
            }
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
    if (c != nullptr)
    {
        if(occupant == nullptr){
            occupant = c;
            cout << "Occupant added to the Shop!"<< endl;
            return true;
        }
        else{
            cout << "The Shop already has an occupant." << endl;
            return false;
        }
    }

    cout << "Cannot add a non-existent citizen to Shop" << endl;
    return false;
}

bool Shop::removeOccupant(Citizen *c){
    if(c!=nullptr){
        if(occupant == nullptr){
            cout << "Shop has no occupant" << endl;
            return true;
        }
        else{
            if(occupant == c){
                occupant = nullptr;
                cout << "Occupant removed!" << endl;
                return true;
            }
            else{
                cout << "Occupant not found." << endl;
                return false;
            }
        }
    }

    cout << "Cannot remove a non-existent citizen from Shop" << endl;
    return false;
}

Building *Shop::clone()
{
    Shop *newBuilding = new Shop();
    newBuilding->state = this->state->clone();
    newBuilding->cleanliness = this->cleanliness;
    newBuilding->electricityUnits = this->electricityUnits;
    newBuilding->waterUnits = this->waterUnits;
    newBuilding->value = this->value;
    newBuilding->area = this->area;    
    newBuilding->capacity = this->capacity;

    return newBuilding;
}

bool Shop::isOccupied()
{
    return occupant != nullptr;
}
