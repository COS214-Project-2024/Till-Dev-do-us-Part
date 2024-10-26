#include "Mall.h"

Mall::Mall():Commercial("Mall")
{
}

bool Mall::addStore(Commercial* building){
    if(stores.size() < capacity){
        stores.push_back(building);
        cout << "New building added"<< endl;

        return true;
    }
    cout << "Could not build, not enough land/space" << endl;
    return false;
} 

void Mall::demolish()
{
    this->~Mall();
}

bool Mall::clean()
{
    for (vector<Commercial*>::iterator it = stores.begin(); it != stores.end(); ++it)
    {

        if(!(*it)->clean()){
            cout << "Building " << (*it) <<" could not be cleaned (not enough water or electricity)" << endl;
            return false;
        }
    }
    cout << "All buildings in " << this << " were cleaned";
    return true;
}

bool Mall::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        for (vector<Commercial *>::iterator it = stores.begin(); it != stores.end(); it++)
        {
            if ((*it)->addOccupant(c))
            {
                return true;
            }
        }
    }

    return false;
}

Mall::~Mall()
{
    for (int i = 0; i < stores.size(); ++i)
    {
        delete stores.at(i);
    }
}
