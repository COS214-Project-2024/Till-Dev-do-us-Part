/**
 * @file Adult.h
 * @brief Defines the Adult class, representing an adult citizen with attributes like balance, net worth, employment status, and housing.
 * 
 * The Adult class extends Citizen, adding specific attributes and actions relevant to adult citizens, such as financial management, employment status, 
 * housing assignment, and actions related to daily routines like going to work.
 * 
 * @version 1.1
 * @date Updated: November 4, 2024
 * 
 * Author: Karabo
 */

#ifndef ADULT_H
#define ADULT_H

#include "Citizen.h"
#include "Building.h"

class Business;

/**
 * @class Adult
 * @brief A class representing an adult citizen with financial, employment, and housing attributes.
 * 
 * This class inherits from Citizen and includes attributes such as balance, net worth, employment, and housing. 
 * It also provides functionality to manage the Adult's job, salary, mood, housing, and daily activities.
 */
class Adult : public Citizen {
protected:
    float balance;       /**< Financial balance of the Adult */
    float netWorth;      /**< Total net worth of the Adult */
    Business* job;       /**< Pointer to the Adult's job, if employed */
    Building* house;     /**< Pointer to the Adult's house, if assigned */

public:
    /**
     * @brief Constructs an Adult object with default attributes.
     * 
     * Initializes mood, balance, net worth, and employment status. 
     * Sets job and house pointers to nullptr.
     */
    Adult();

    /**
     * @brief Creates a new Adult object as a clone of the current one.
     * 
     * @return Citizen* A pointer to a new Adult object.
     * 
     * @details This method creates a duplicate of the current Adult instance, useful for situations requiring an identical instance.
     */
    virtual Citizen* clone();

    /**
     * @brief Updates the Adult's mood by invoking a reaction.
     * 
     * Deletes the current mood and replaces it with a new mood as determined by the current mood's reaction function.
     */
    virtual void react();

    /**
     * @brief Prepares the Adult to perform work-related actions.
     * 
     * Simulates actions like using utilities before leaving the house for work. 
     * This method is a placeholder and will be expanded in future implementations.
     */
    virtual void goToWork();

    /**
     * @brief Checks if the Adult is employed.
     * 
     * @return true if the Adult has a job; false otherwise.
     */
    virtual bool employmentStatus();

    /**
     * @brief Indicates whether the Adult has a child.
     * 
     * @return false, as this implementation assumes no children for Adult instances.
     */
    virtual bool hasChild();

    /**
     * @brief Adds a specified salary amount to the Adult's balance.
     * 
     * @param salary The amount to be added to the Adult's balance.
     */
    virtual void salary(float salary);

    /**
     * @brief Checks if the Adult has a house assigned.
     * 
     * @return true if the Adult has a house; false otherwise.
     */
    virtual bool hasHouse();

    /**
     * @brief Retrieves the Adult's assigned house.
     * 
     * @return Building* A pointer to the assigned house, or outputs a message if no house is assigned.
     */
    virtual Building* getHouse();

    /**
     * @brief Sets the Adult's job to a specified Business.
     * 
     * @param job A pointer to a Business object representing the Adult's employment.
     * 
     * @details This allows for assigning or changing the Adult's employment status.
     */
    virtual void setJob(Business* job);

    /**
     * @brief Assigns a house to the Adult.
     * 
     * @param h A pointer to the Building object representing the Adult's house.
     * 
     * @details Sets the house pointer and adds the Adult as an occupant to the specified house.
     */
    virtual void setHouse(Building* h);

    /**
     * @brief Deducts a specified amount from the current balance or budget.
     * 
     * This function reduces the adult's available funds by the provided amount.
     * 
     * @param amount The amount to be deducted.
     */
    virtual void spendMoney(float amount); 

    /**
     * @brief Destructor for the Adult class.
     * 
     * Frees any dynamically allocated resources (if any) upon deletion of an Adult instance.
     */
    virtual ~Adult() {};
};

#endif // ADULT_H
