#include "Water.h"

/**
 * @brief Constructs a Water resource with a specified initial amount.
 * The resource is initialized with the name "Water" and an initial amount of 100000 litres.
 * 
 * @author Thendo
 */
Water::Water() : Resources("Water", 100000) {}

/**
 * @brief Displays the available quantity of water.
 * 
 * This method retrieves the current amount of water and prints it to the console in litres.
 */
float Water::getAvailableQuantity()
{
    return getCurrentAmount();
}

/**
 * @brief Retrieves the name of the water resource.
 * @return A string representing the name of the resource as "Water".
 */
std::string Water::getName() const
{
    return "Water";
}
