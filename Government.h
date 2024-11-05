#ifndef GOVERNMENT_H
#define GOVERNMENT_H
#include <map>
#include <string>
#include <vector>
#include "Department.h"
#include "SocialAffairsDept.h"
#include "Policy.h"
#include "Memento.h"

/**
 * @class Government
 * @brief Singleton class managing departments and policies within a government.
 */
class Government {
private:
    static Government* instance; /**< Singleton instance of the Government class. */
    std::vector<Policy*> policies; /**< Vector holding active government policies. */
    std::map<std::string, Department*> departments; /**< Map of department names to department instances. */
    Memento* memento; /**< Memento to store and restore policy states. */
    float budget; /**< Government budget. */

    /**
     * @brief Private constructor for singleton pattern.
     */
    Government();

public:
    /**
     * @brief Provides access to the singleton instance of Government.
     * @return Pointer to the singleton instance.
     */
    static Government* getInstance();

    /**
     * @brief Deletes the singleton instance.
     */
    static void deleteInstance();

    /**
     * @brief Destructor cleans up allocated memory.
     */
    ~Government();

    /**
     * @brief Retrieves a department by name.
     * @param name Name of the department.
     * @return Pointer to the requested Department.
     */
    Department* getDepartment(std::string name);

    /**
     * @brief Enacts a new policy in the government.
     * @param policy Pointer to the Policy being enacted.
     */
    void enactPolicy(Policy* policy);

    /**
     * @brief Reverts a specific policy by name.
     * @param name Name of the policy to revert.
     */
    void revertPolicy(std::string name);

    /**
     * @brief Adds a department to the government.
     * @param name Name of the department.
     * @param department Pointer to the Department to add.
     */
    void addDepartment(std::string name, Department* department);

    /**
     * @brief Removes a department from the government by name.
     * @param name Name of the department to remove.
     */
    void removeDepartment(std::string name);

    /**
     * @brief Creates a memento of the current policy state.
     * @return Pointer to the Memento containing the saved state.
     */
    Memento* createMemento();

    /**
     * @brief Restores policies from a memento.
     * @param memento Pointer to the Memento to restore from.
     */
    void setMemento(Memento* memento);

    /**
     * @brief Retrieves the list of active policies.
     * @return Vector of pointers to active policies.
     */
    std::vector<Policy*> getPolicies(){return policies;}
};

#endif
