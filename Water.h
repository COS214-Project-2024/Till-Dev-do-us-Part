#ifndef WATER_H
#define WATER_H

#include "Resources.h"

/**
 * @class Water
 * @brief Represents the water resource, inheriting from the Resources class.
 * 
 * This class manages the water resource and provides methods to retrieve its
 * available quantity and name.
 * 
 * @author Thendo
 */
class Water : public Resources {
public:
    /**
     * @brief Constructs a Water resource with an initial amount of 100000 litres.
     */
    Water();

    /**
     * @brief Displays the available quantity of water.
     * 
     * This method returns the current amount of water .
     */
    float getAvailableQuantity();

    /**
     * @brief Retrieves the name of the water resource.
     * @return A string representing the name of the resource as "Water".
     */
    std::string getName() const override;
    
};

#endif // WATER_H
