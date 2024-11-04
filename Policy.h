#ifndef POLICY_H
#define POLICY_H

#include <string>
#include <vector>
#include "Memento.h"

/**
 * @brief The Policy class represents a government policy with a name, code, and description.
 */
class Policy {
private:
    std::string name;         ///< The name of the policy.
    std::string code;         ///< The code of the policy.
    std::string description;  ///< The description of the policy.

public:
    /**
     * @brief Constructs a Policy with a given name, code, and description.
     * @param name The name of the policy.
     * @param code The unique code identifier for the policy.
     * @param description A brief description of the policy.
     */
    Policy(std::string name, std::string code, std::string description);

    /**
     * @brief Gets the description of the policy.
     * @return A string containing the policy description.
     */
    std::string getDescription();

    /**
     * @brief Gets the name of the policy.
     * @return A string containing the policy name.
     */
    std::string getName();

    /**
     * @brief Destructor for Policy.
     */
    ~Policy();
};

#endif
