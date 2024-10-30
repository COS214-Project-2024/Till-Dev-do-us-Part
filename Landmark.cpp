#include "Landmark.h"
Landmark::Landmark(string type):Building(type)
{

}

void Landmark::demolish()
{
    cout << "Removing everyone from the "<< this->type << endl;
    occupants.clear();
}

bool Landmark::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        if (occupants.size() < capacity)
        {
            occupants.push_back(c);
            cout << "Citizen added to " << this->type << endl;
            return true;
        }
        cout << "Citizen " << c << " could not be added to " << this->type << "." << this->type << " at capacity " << endl;
        return false;
    }

    cout << "Citizen is non existent" << endl;
    return false;
}