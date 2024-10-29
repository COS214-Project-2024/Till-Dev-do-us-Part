#include "Energy.h"

Energy::Energy() : Resources("Energy", 100000) {}

void Energy::getAvailableQuantity()
{
    cout<< getCurrentAmount()<< " kWh."<<endl;
}
