#include "Energy.h"

/**
 * @brief Constructs an Energy resource with a specified initial amount.
 * 
 * This constructor initializes the Energy resource with the name "Energy"
 * and sets the initial amount to 100,000.
 * 
 * @author Thendo
 */
Energy::Energy() : Resources("Energy", 100000) {}

/**
 * @brief Displays the available quantity of energy.
 * 
 * This method outputs the current amount of energy in kilowatt-hours (kWh).
 */
float Energy::getAvailableQuantity()
{
    return getCurrentAmount();
}

/**
 * @brief Retrieves the name of the energy resource.
 * @return A string indicating the resource name as "Energy".
 */
std::string Energy::getName() const
{
    return "Energy";
}
