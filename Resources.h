#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>
#include <vector>
#include <chrono>
#include "ResourceState.h"
#include "SurplusState.h"

using namespace std;

class ResourceState;
class ResourceObserver;

/**
 * @class Resources
 * @brief Manages a resource with states, consumption, and restoration functionality.
 * 
 * @author Thendo
 */
class Resources
{
private:
    ResourceState* resState;               /**< Pointer to the current state of the resource. */
    float currentAmount;                   /**< Current amount of the resource available. */
    const float INITIAL_AMOUNT;            /**< Initial (full) amount of the resource. */
    string resourceName;                   /**< Name of the resource. */
    bool isRestoring;                      /**< Flag indicating if the resource is being restored. */
    std::chrono::steady_clock::time_point restoreStartTime; /**< Timestamp for restoration start. */

public:
    /**
     * @brief Constructs a resource with a specified name and initial amount.
     * @param name The name of the resource.
     * @param initialAmount The initial amount of the resource.
     */
    Resources(string name, float initialAmount);

    /**
     * @brief Destructor for Resources class, cleans up any dynamically allocated memory.
     */
    virtual ~Resources();

    /**
     * @brief Tracks the resource by checking availability based on the current state.
     */
    void trackResources();

    /**
     * @brief Gets the current state of the resource as a string.
     * @return The current state status of the resource.
     */
    string getState();

    /**
     * @brief Sets a new state for the resource and alerts about the state change.
     * @param resourceState Pointer to the new ResourceState.
     */
    void setState(ResourceState* resourceState);

    /**
     * @brief Retrieves the current amount of the resource.
     * @return The current amount of the resource.
     */
    float getCurrentAmount() const;

    /**
     * @brief Gets the initial (full) amount of the resource.
     * @return The initial amount of the resource.
     */
    float getInitialAmount() const;

    /**
     * @brief Retrieves the name of the resource.
     * @return The name of the resource.
     */
    virtual string getName() const;

    /**
     * @brief Consumes a specified amount of the resource if available, handles restoration if needed.
     * @param amount The amount to consume.
     * @return True if the consumption was successful, false otherwise.
     */
    bool consume(float amount);

    /**
     * @brief Sends an alert with the resource’s current status, amount, and percentage remaining.
     */
    void alert();
};

#endif // RESOURCES_H
