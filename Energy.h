#ifndef ENERGY_H
#define ENERGY_H

#include "Resources.h"

/**
 * @class Energy
 * @brief Represents an energy resource, inheriting from Resources.
 * 
 * This class manages the energy resource, including its available quantity
 * and name.
 * 
 * @author Thendo
 */
class Energy : public Resources {
public:
    /**
     * @brief Constructs an Energy resource with a specified initial amount.
     * 
     * This constructor initializes the Energy resource with the name "Energy"
     * and sets the initial amount to a predefined value.
     */
    Energy();

    /**
     * @brief Displays the available quantity of energy.
     * 
     * This method outputs the current amount of energy in kilowatt-hours (kWh).
     */
    float getAvailableQuantity();

    /**
     * @brief Retrieves the name of the energy resource.
     * @return A string indicating the resource name as "Energy".
     */
    std::string getName() const override;
};

#endif // ENERGY_H
