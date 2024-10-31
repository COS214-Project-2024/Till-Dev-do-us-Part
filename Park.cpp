#include "Park.h"

Park::Park():Landmark("Park")
{

}

Building* Park::clone(){
    
}

bool Park::clean()
{
    if(useWater(40) && useElectricity(10)){
        cout << "Park is now clean." << endl;
        return true;
    }
    cout << "Park does not have enough water or electricity." << endl;
    return true;
}
