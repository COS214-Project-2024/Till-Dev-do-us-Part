#include "Energy.h"

Energy::Energy() : Resources("Energy", 100000) {}

void Energy::getAvailableQuantity()
{
    cout << getCurrentAmount() << " kWh." << endl;
}

std::string Energy::getName() const
{
    return "Energy";
}
