/**
 * @file Minor.h
 * @brief Defines the Minor class, representing a child Citizen with associated attributes and behaviors.
 * @author Karabo
 */

#ifndef MINOR_H
#define MINOR_H

#include "Citizen.h"
#include "Adult.h"
#include "School.h"

/**
 * @class Minor
 * @brief A class representing a Minor citizen who can interact with adults and attend school.
 * 
 * Inherits from the Citizen class and provides functionalities specific to a minor.
 */
class Minor : public Citizen {
private:
    School* school; /**< Pointer to the School object representing the Minor's school. */
    Adult* parent;  /**< Pointer to the Adult object representing the Minor's parent. */

public:
    /**
     * @brief Constructs a Minor object, initializing its mood and health attributes.
     */
    Minor();

    /**
     * @brief Clones the current Minor object.
     * 
     * @return Citizen* A pointer to a new Minor object that is a copy of this Minor.
     */
    virtual Citizen* clone();

    /**
     * @brief Triggers a reaction based on the Minor's current mood.
     */
    virtual void react();

    /**
     * @brief Placeholder for school-related behavior.
     * 
     * This function will define how the Minor interacts with school.
     */
    void goToSchool();

    /**
     * @brief Sets the parent of the Minor.
     * 
     * @param p A pointer to the Adult object representing the Minor's parent.
     */
    void setParent(Adult* p);

    /**
     * @brief Virtual destructor for the Minor class.
     * 
     * Allows for proper cleanup of derived classes when a pointer to Minor is deleted.
     */
    virtual ~Minor() {}
};

#endif // MINOR_H