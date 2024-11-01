#include "Citizen.h"
#include "Building.h"
#include "Residential.h"
void Citizen::goToWork()
{
    if (building->useStove())
    {
        // cout << "\033[1;31m Citizen could not use stove to make skhaftin. Hence not going to work\033[0m\n";
        return;
    }
    if (building->useShower())
    {
        cout << "\033[1;31m Citizen could not use shower, and smells bad. Hence not going to work\033[0m\n";
        return;
    }
    if (building->useToilet())
    {
        cout << "\033[1;31m Citizen could not use toilet, and messed their pants. Hence not going to work\033[0m\n";
        return;
    }

    cout << "\033[1;32m Citizen going to work\033[0m\n";
    return;
}

void Citizen::addHome(Residential *b)
{
    if (b != nullptr)
    {
        if (this->building != nullptr)
        {
            cout << "Citizen already has a building to reside in" << endl;
        }
        else
        {
            this->building = b;
            cout << "Citizen was assigned new building" << endl;
        }
    }
    else
    {
        cout << "Passed in building is null" << endl;
    }
}