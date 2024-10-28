#include <iostream>
#include "ResourceDepartment.h"
#include "Building.h"
#include "Citizen.h"
#include "PowerPlant.h"
#include "WaterSupply.h"
#include "WasteManagement.h"
#include "SewageSystem.h"

int main()
{
    ResourceDepartment resourceDepartment;

    // Initialize specific utilities and register them
    Utility *powerPlant = new PowerPlant();
    Utility *waterSupply = new WaterSupply();
    Utility* wasteManagement = new WasteManagement(500);
    SewageSystem* sewageSystem = new SewageSystem(500);

    resourceDepartment.addUtility(powerPlant);
    resourceDepartment.addUtility(waterSupply);
    resourceDepartment.addUtility(wasteManagement);
    resourceDepartment.addUtility(sewageSystem);

    // Create resources and add them to the ResourceDepartment (optional for simulation)
    // Create and register buildings, citizens, and simulate resource requests and delivery...

    // Simulate service delivery from utilities
    // resourceDepartment.update();

    // Cleanup
    delete powerPlant;
    delete waterSupply;
    delete wasteManagement;
    delete sewageSystem;

    return 0;
}
