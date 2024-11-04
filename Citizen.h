/**
 * @file Citizen.h
 * @brief Defines the Citizen class, representing a person in the system with attributes such as mood and health.
 * @author Karabo
 */

#ifndef CITIZEN_H
#define CITIZEN_H

#include <iostream>
#include <string>
#include "Feeling.h"

class Business;

/**
 * @class Citizen
 * @brief Abstract base class for representing a citizen with attributes and behaviors related to health and mood.
 * 
 * This class defines the common interface for all types of citizens in the system, including methods for
 * health management and mood reactions. Derived classes must implement the clone and react methods.
 */
class Citizen {

protected:
    Feeling* mood; /**< Pointer to the Feeling object representing the Citizen's mood */
    int health;    /**< The health status of the Citizen */

public:
    /**
     * @brief Creates a clone of the Citizen object.
     * 
     * @return Citizen* A pointer to a new Citizen object that is a clone of the current instance.
     * 
     * @note This method is pure virtual and must be implemented by derived classes.
     */
    virtual Citizen* clone() = 0;

    /**
     * @brief Triggers a reaction based on the Citizen's current mood.
     * 
     * @note This method is pure virtual and must be implemented by derived classes.
     */
    virtual void react() = 0;

    /**
     * @brief Retrieves the current health of the Citizen.
     * 
     * @return int The current health value of the Citizen.
     */
    virtual int getHealth();

    /**
     * @brief Sets the health of the Citizen to a specified value.
     * 
     * @param h The new health value to assign to the Citizen.
     */
    virtual void setHealth(int h);

    /**
     * @brief Retrieves the name of the current mood of the Citizen.
     * 
     * @return std::string The name of the Citizen's mood.
     */
    virtual std::string getFeeling();

    /**
     * @brief Destructor for the Citizen class.
     * 
     * Cleans up the dynamically allocated mood object to prevent memory leaks.
     */
    virtual ~Citizen();
};

#endif // CITIZEN_H
