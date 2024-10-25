#include "House.h"

House::House():Residential("Hoose")
{

}

House::~House()
{
    occupants.clear();
}

void House::demolish(){
    //must call destructor
}

bool House::useShower(){
    return useWater(80) && useElectricity(40);
}

bool House::useToilet(){
    return useWater(8);
}

bool House::useStove(){
    return useElectricity(40);
}

bool House::clean(){
    return useWater(200) && useElectricity(40);
}


