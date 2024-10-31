#include "Office.h"

Office::Office():Commercial("Office"){
    area = 800;
    value = 12000;
    capacity =1;
    occupant = nullptr;
}

Office::~Office(){
    demolish();
    cout << "Office demolished!" << endl;
}

void Office::demolish(){
    cout << "Removing occupant from the Office" << endl;
    occupant = nullptr;
}

bool Office::clean()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(150) && useElectricity(40))
        {
            cout << "Office cleaned.";
            if (cleanliness + 30 >= 100)
            {
                cleanliness = 100;
            }
            else
            {
                if (cleanliness <= 0 && cleanliness + 30 >= 0 && waterUnits > 0 && electricityUnits > 0)
                {
                    delete state;
                    state = new CompleteState();
                    cout << "Office is now in Operational state" << endl;
                }
                cleanliness += 30;
            }
            return true;
        }
        cout << "Not enough water or electricity to clean the Office:" << endl;
        cout << "Required water to clean: 150" << endl;
        cout << "Required electricity to clean: 40" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "Office is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

bool Office::addOccupant(Citizen *c){
    if (c != nullptr)
    {
        if (occupant == nullptr)
        {
            occupant = c;
            cout << "Occupant added to the Office!" << endl;
            return true;
        }
        else
        {
            cout << "The Office already has an occupant." << endl;
            return false;
        }
    }

    cout << "Cannot add a non-existent citizen to Oddice" << endl;
    return false;
}

bool Office::removeOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        if (occupant == nullptr)
        {
            cout << "Office has no occupant" << endl;
            return true;
        }
        else
        {
            if (occupant == c)
            {
                occupant = nullptr;
                cout << "Occupant removed!" << endl;
                return true;
            }
            else
            {
                cout << "Occupant not found." << endl;
                return false;
            }
        }
    }

    cout << "Cannot remove a non-existent citizen from Office" << endl;
    return false;
}

Building *Office::clone()
{
    Office *newBuilding = new Office();
    newBuilding->state = this->state->clone();
    newBuilding->cleanliness = this->cleanliness;
    newBuilding->electricityUnits = this->electricityUnits;
    newBuilding->waterUnits = this->waterUnits;
    newBuilding->value = this->value;
    newBuilding->area = this->area;
    newBuilding->capacity = this->capacity;
    return newBuilding;
}

bool Office::isOccupied()
{
    return occupant != nullptr;
}