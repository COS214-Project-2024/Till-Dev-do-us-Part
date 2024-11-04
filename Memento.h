#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>
#include <vector>

class Policy;  // Forward declaration

/**
 * @brief The Memento class captures and restores the state of active policies.
 */
class Memento {
private:
    std::vector<Policy*> activePolicies;  ///< A list of pointers to active policies.

public:
    /**
     * @brief Default constructor for Memento.
     */
    Memento();

    /**
     * @brief Retrieves a copy of the active policies.
     * @return A vector containing copies of active policies.
     */
    std::vector<Policy*> getActivePolicies();

    /**
     * @brief Sets active policies to a given list of policies.
     * @param policies A vector of Policy pointers to be set as active policies.
     */
    void setActivePolicies(std::vector<Policy*> policies);

    /**
     * @brief Destructor for Memento, responsible for cleaning up dynamically allocated policies.
     */
    ~Memento();
};

#endif
