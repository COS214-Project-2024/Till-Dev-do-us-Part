#ifndef RESOURCESTATE_H
#define RESOURCESTATE_H

#include <iostream>
using namespace std;

class Resource;

/**
 * @class ResourceState
 * @brief Abstract base class representing the state of a resource.
 * Defines the interface for state-specific behavior.
 * 
 * @author Thendo
 */
class ResourceState {
public:
    /**
     * @brief Checks the availability of a resource and performs actions based on the current state.
     * @param resource Pointer to the Resources object.
     */
    virtual void checkAvailability(Resources* resource) = 0;

    /**
     * @brief Gets the status of the current state as a string.
     * @return A string representing the current status of the resource state.
     */
    virtual string getStatus() = 0;

    /**
     * @brief Virtual destructor for ResourceState to allow derived class cleanup.
     */
    virtual ~ResourceState() = default;
};

#endif // RESOURCESTATE_H
