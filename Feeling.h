/**
 * @file Feeling.h
 * @brief Header file for the Feeling class, representing emotional states.
 * @author Karabo
 */

#ifndef FEELING_H
#define FEELING_H

#include <string>

/**
 * @class Feeling
 * @brief Abstract base class representing an emotional state.
 */
class Feeling {
protected:
    std::string name; ///< The name of the feeling.

public:
    /**
     * @brief Pure virtual function that defines how a feeling reacts.
     * 
     * @return Feeling* Pointer to a new Feeling instance representing the reaction.
     */
    virtual Feeling* reaction() = 0; // Pure virtual function for reaction

    /**
     * @brief Gets the name of the feeling.
     * 
     * @return const std::string& The name of the feeling.
     */
    virtual std::string getName() const {
        return name;
    }

    /**
     * @brief Destructor for the Feeling class.
     * 
     * Ensures proper cleanup of derived classes.
     */
    virtual ~Feeling() {}
};

#endif // FEELING_H