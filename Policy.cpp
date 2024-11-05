#include "Policy.h"
#include <iostream>

/**
 * @brief Constructs a Policy with specified name, code, and description.
 * @param name The name of the policy.
 * @param code The unique code identifier for the policy.
 * @param description A brief description of the policy.
 */
Policy::Policy(std::string name, std::string code, std::string description)
    : name(name), code(code), description(description) {}

/**
 * @brief Gets the name of the policy.
 * @return The name of the policy as a string.
 */
std::string Policy::getName()
{
    return name;
}

/**
 * @brief Gets the description of the policy.
 * @return The description of the policy as a string.
 */
std::string Policy::getDescription()
{
    return description;
}

/**
 * @brief Destructor for Policy.
 */
Policy::~Policy()
{
    // Destructor logic if necessary
}
