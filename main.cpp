#include "Resources.h"
#include "Water.h"
#include "Energy.h"
#include "Materials.h"
#include <iostream>
#include "PowerPlant.h"
#include "WaterSupply.h"
#include "OperationalProductionState.h"
#include "MaintenanceProductionState.h"
#include "OutageProductionState.h"
#include "ResourceDepartment.h"
#include "Energy.h"
#include "Water.h"

void simulationOne()
{
    // Create Resource Department
    ResourceDepartment *resourceDept;

    // Create Energy and Water Resources
    Resources *energyResource = new Energy();
    Water *waterResource = new Water();

    // Create PowerPlant and WaterSupply objects
    ProductionUtility *powerPlant = new PowerPlant("CityPower", resourceDept, energyResource);
    ProductionUtility *waterSupply = new WaterSupply("CityWater", resourceDept, waterResource);

    // Create Production States
    OperationalProductionState *operationalState = new OperationalProductionState();
    MaintenanceProductionState *maintenanceState = new MaintenanceProductionState();
    OutageProductionState *outageState = new OutageProductionState();

    // Start in Operational State for both utilities
    std::cout << "\n--- Starting Production in Operational State ---\n";
    powerPlant->setProState(operationalState);
    waterSupply->setProState(operationalState);

    powerPlant->getStatus();
    // waterSupply->getStatus();

    powerPlant->startProduction();
     powerPlant->getStatus();
    
    // waterSupply->startProduction();

   
    // waterSupply->getStatus();

    // // Transition to Maintenance State
    // std::cout << "\n--- Switching to Maintenance State ---\n";
    // powerPlant->setProState(maintenanceState);
    // waterSupply->setProState(maintenanceState);

    // powerPlant->startProduction();
    // waterSupply->startProduction();

    // // Transition to Outage State
    // std::cout << "\n--- Switching to Outage State ---\n";
    // powerPlant.setProductionState(&outageState);
    // waterSupply.setProductionState(&outageState);

    // powerPlant.startProduction();
    // waterSupply.startProduction();
}

int main()
{

    simulationOne();

    return 0;
}
