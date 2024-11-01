/**
 * @file Adult.h
 * @brief Defines the Adult class, representing an adult citizen with attributes like balance, net worth, and employment status, and provides methods to manage these attributes and actions related to employment and mood reactions.
 * @author Karabo 
 */

#ifndef ADULT_H
#define ADULT_H

#include "Citizen.h"

/**
 * @class Adult
 * @brief A class representing an adult citizen with financial and employment-related attributes.
 * 
 * Inherits from the Citizen class and adds functionality specific to adult citizens, such as managing balance, net worth, employment, and job-related actions.
 */
class Adult : public Citizen {

protected:
    float balance;   /**< The financial balance of the Adult */
    float netWorth;  /**< The total net worth of the Adult */
    Business* job;   /**< Pointer to the Adult's job, if employed */

public:
    /**
     * @brief Constructs an Adult object with default attributes.
     */
    Adult();

    /**
     * @brief Creates a new Adult object as a clone of the current one.
     * 
     * @return Citizen* A pointer to a new Adult object.
     */
    virtual Citizen* clone();

    /**
     * @brief Updates the Adult's mood by invoking a reaction.
     */
    virtual void react();

    /**
     * @brief Placeholder method for the Adult to perform work-related actions.
     */
    virtual void goToWork();

    /**
     * @brief Checks if the Adult is employed.
     * 
     * @return true if the Adult has a job, false otherwise.
     */
    virtual bool employmentStatus();

    /**
     * @brief Indicates whether the Adult has a child.
     * 
     * @return false by default.
     */
    virtual bool hasChild();

    /**
     * @brief Adds a specified salary amount to the Adult's balance.
     * 
     * @param salary The amount to be added to the Adult's balance.
     */
    virtual void salary(float salary);

    /**
     * @brief Sets the Adult's job to a specified Business.
     * 
     * @param job A pointer to a Business object representing the Adult's employment.
     */
    virtual void setJob(Business* job);

    /**
     * @brief Destructor for the Adult class.
     */
    virtual ~Adult() {};

};

#endif // ADULT_H
