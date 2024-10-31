#include "Water.h"

Water::Water() : Resources("Water", 100000) {}

void Water::getAvailableQuantity()
{
    cout<< getCurrentAmount()<< " Litres."<<endl;
}

std::string Water::getName() const{
    return "Water";
}
