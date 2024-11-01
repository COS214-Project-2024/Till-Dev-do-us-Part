/**
 * @file BuyCar.h
 * @brief Defines the BuyCar decorator class, allowing a Citizen to own a car and manage related financial operations.
 * @author Karabo
 */

#ifndef BUYCAR_H
#define BUYCAR_H

#include "LifeStage.h"
#include "Transport.h"

/**
 * @class BuyCar
 * @brief A decorator class that adds car ownership functionality to a Citizen.
 * 
 * This class inherits from LifeStage and allows for the purchase and management
 * of a car by a Citizen, including handling associated financial implications.
 */
class BuyCar : public LifeStage {

private:
    Transport* car; /**< Pointer to the Transport object representing the car owned by the Citizen */

public:
    /**
     * @brief Constructs a BuyCar object that decorates a Citizen with car-buying capabilities.
     * 
     * @param adult A pointer to a Citizen object (typically an Adult) who can purchase a car.
     */
    BuyCar(Citizen* adult);

    /**
     * @brief Facilitates the purchase of a car by the Citizen.
     * 
     * @param car A pointer to a Transport object representing the car to be purchased.
     */
    void buyCar(Transport* car);

    /**
     * @brief Destructor for the BuyCar class.
     * 
     * Cleans up the dynamically allocated resources associated with the Citizen and the car.
     */
    virtual ~BuyCar();
};

#endif // BUYCAR_H
