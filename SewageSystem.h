/**
 * @file SewageSystem.h
 * @brief Defines the SewageSystem class for managing sewage services in the simulation.
 */

#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "ServiceUtility.h"

/**
 * @class SewageSystem
 * @brief Represents a sewage management utility that provides sewage services.
 */
class SewageSystem : public ServiceUtility {
public:
    /**
     * @brief Constructs a SewageSystem with specified parameters.
     * @param name Name of the sewage system
     * @param department Pointer to the Resource Department
     */
    SewageSystem(std::string name, ResourceDepartment* department,WiseBucks* app);

    /**
     * @brief Default destructor for SewageSystem.
     */
    ~SewageSystem();

    /**
     * @brief Starts the sewage management service.
     */
    void startService() override;  

    /**
     * @brief Creates a new Development Department (not implemented).
     * @return Pointer to the DevelopmentDept
     */
    DevelopmentDept* createDevelopmentDept() override;
};

#endif // SEWAGESYSTEM_H
