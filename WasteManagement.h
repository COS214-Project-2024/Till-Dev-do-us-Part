/**
 * @file WasteManagement.h
 * @brief Defines the WasteManagement class for managing waste services in the simulation.
 */

#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "ServiceUtility.h"
#include "ServiceState.h"
#include <vector>

/**
 * @class WasteManagement
 * @brief Represents a waste management utility that provides waste services.
 */
class WasteManagement : public ServiceUtility
{
private:
    // std::vector<Building *> buildings; // Future use for managing buildings
    // BuildingIterator iterator; // Future use for iterating over buildings

public:
    /**
     * @brief Constructs a WasteManagement utility with specified parameters.
     * @param name Name of the waste management utility
     * @param department Pointer to the Resource Department
     */
    WasteManagement(std::string name, ResourceDepartment *department,WiseBucks* app);

    /**
     * @brief Default destructor for WasteManagement.
     */
    ~WasteManagement();

    /**
     * @brief Starts the waste management service.
     */
    void startService() override;

    /**
     * @brief Creates a new Development Department (not implemented).
     * @return Pointer to the DevelopmentDept
     */
    DevelopmentDept* createDevelopmentDept() override;

    // Future use for iterating over buildings (commented out)
    // void iterateBuildings(bool limitedProcessing, int maxBuildings) override;
};

#endif // WASTEMANAGEMENT_H
