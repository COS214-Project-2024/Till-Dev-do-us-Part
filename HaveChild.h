/**
 * @file HaveChild.h
 * @brief Defines the HaveChild class, representing the ability of a Citizen to have children.
 * @author Karabo
 */

#ifndef HAVECHILD_H
#define HAVECHILD_H

#include "LifeStage.h"
#include "Transport.h"
#include "Minor.h"

/**
 * @class HaveChild
 * @brief A class that allows a Citizen to have children.
 * 
 * Inherits from the LifeStage class and provides functionality to manage a child
 * associated with the adult Citizen.
 */
class HaveChild : public LifeStage {
private:
    Citizen* child; /**< Pointer to the Citizen object representing the child. */

public:
    /**
     * @brief Constructs a HaveChild object, associating it with a specific adult Citizen.
     * 
     * @param adult A pointer to the Citizen object representing the adult who can have children.
     */
    HaveChild(Citizen* adult);

    /**
     * @brief Assigns a child to the adult Citizen.
     * 
     * @param baby A pointer to the Citizen object representing the child.
     */
    void haveChild(Citizen* baby);

    /**
     * @brief Checks if the adult Citizen has a child.
     * 
     * @return bool Always returns true, indicating that this class represents a Citizen capable of having children.
     */
    virtual bool hasChild();

    /**
     * @brief Destructor for the HaveChild class.
     * 
     * Cleans up any dynamically allocated memory associated with the child.
     */
    virtual ~HaveChild();
};

#endif // HAVECHILD_H
