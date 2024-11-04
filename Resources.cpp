#include "Resources.h"
#include <thread>

/**
 * @brief Constructs a Resources object with a given name and initial amount.
 * Initializes the resource in a Surplus state.
 * 
 * @param name The name of the resource.
 * @param initialAmount The initial amount of the resource.
 * @author Thendo
 */
Resources::Resources(string name, float initialAmount) 
    : INITIAL_AMOUNT(initialAmount), resourceName(name), isRestoring(false)
{
    currentAmount = INITIAL_AMOUNT;
    resState = new SurplusState();  // Initially, the resource is in Surplus state
}

/**
 * @brief Destructor for the Resources class.
 * Cleans up the dynamically allocated resource state.
 */
Resources::~Resources()
{
    delete resState;
}

/**
 * @brief Tracks the resource by delegating the availability check to the current state.
 */
void Resources::trackResources()
{
    resState->checkAvailability(this);
}

/**
 * @brief Gets the current state status of the resource.
 * 
 * @return A string representing the status of the resource.
 */
string Resources::getState()
{
    return resState->getStatus();
}

/**
 * @brief Sets a new state for the resource, deleting the old state to prevent memory leaks.
 * Alerts about the state change.
 * 
 * @param resourceState A pointer to the new ResourceState.
 */
void Resources::setState(ResourceState* resourceState)
{
    if (resState != nullptr)
        delete resState;  // Delete old state to avoid memory leaks
    resState = resourceState;  // Set new state
    alert();  // Notify about the change
}

/**
 * @brief Retrieves the current amount of the resource.
 * 
 * @return The current amount of the resource.
 */
float Resources::getCurrentAmount() const
{
    return currentAmount;
}

/**
 * @brief Gets the initial amount of the resource.
 * 
 * @return The initial amount of the resource.
 */
float Resources::getInitialAmount() const
{
    return INITIAL_AMOUNT;
}

/**
 * @brief Sends an alert about the resource's current status, amount, and percentage remaining.
 */
void Resources::alert() {
    float percentage = (currentAmount / INITIAL_AMOUNT) * 100;
    cout << "ALERT: " << resourceName
         << " is now in " << resState->getStatus()
         << " at " << currentAmount
         << " units (" << percentage << "%)" << endl;
}

/**
 * @brief Gets the name of the resource.
 * 
 * @return A string representing the name of the resource.
 */
string Resources::getName() const {
    return resourceName;
}

/**
 * @brief Attempts to consume a specified amount of the resource if available.
 * Checks if the resource is in a critical or shortage state and, if needed,
 * restores the resource. Prevents consumption if the resource is under restoration.
 * 
 * @param amount The amount of the resource to consume.
 * @return True if consumption was successful, otherwise false.
 */
bool Resources::consume(float amount)
{
    // If restoration is in progress, halt consumption
    if (isRestoring) 
    {
        cout << resourceName << " is currently being restored. Production halted.\n";
        return false;
    }
    
    // Validate consumption amount
    if (amount <= 0) {
        cout << "Invalid consumption amount" << endl;
        return false;
    }

    // Define threshold limits for resource states
    float lowerThreshold = INITIAL_AMOUNT * 0.25;  // 25% capacity
    float upperThreshold = INITIAL_AMOUNT * 0.50;  // 50% capacity

    // Check if resource is in critical state and needs restoring
    if (currentAmount < lowerThreshold)
    {
        cout << "Critical state: " << resourceName << " is below 25% capacity. Please wait while restoring.\n";
        
        // Simulate restoration delay
        std::this_thread::sleep_for(std::chrono::seconds(6));
        
        // Restore to full capacity and update state to Surplus
        currentAmount = INITIAL_AMOUNT;
        setState(new SurplusState());
    
        cout << "Restoration completed. You may try to consume again.\n";
        return false;
    }

    // Warn if resource level is between lower and upper thresholds
    if (currentAmount >= lowerThreshold && currentAmount < upperThreshold)
    {
        cout << "Warning: Current " << resourceName << " level is in shortage state." << endl;
    }

    // Check if enough resource is available for consumption
    if (amount > currentAmount)
    {
        cout << "Insufficient " << resourceName << " available" << endl;
        return false;
    }
    
    // Deduct the consumed amount and update state if needed
    currentAmount -= amount;
    cout << amount << " units of " << resourceName << " consumed" << endl;
    trackResources();  // Check if state should change based on new amount

    return true;
}
