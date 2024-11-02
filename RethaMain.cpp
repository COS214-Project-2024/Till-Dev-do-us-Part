// #include "Resources.h"
// #include "Water.h"
// #include "Energy.h"
// #include "Materials.h"
// #include <iostream>
// #include "PowerPlant.h"
// #include "WaterSupply.h"
// #include "OperationalProductionState.h"
// #include "MaintenanceProductionState.h"
// #include "OutageProductionState.h"
// #include "ResourceDepartment.h"
// #include "Energy.h"
// #include "Water.h"
// #include "Resources.h"
//     #include "Water.h"
//     #include "Energy.h"
//     #include "Materials.h"
// #include "ServiceUtility.h"
// #include "PowerPlant.h"
// #include "WaterSupply.h"
// #include "SewageSystem.h"
// #include "WasteManagement.h"
// #include "OperationalProductionState.h"
// #include "MaintenanceProductionState.h"
// #include "OutageProductionState.h"
// #include "ResourceDepartment.h"


// void simulationOne()
// {
//     // Create Resource Department
//     ResourceDepartment *resourceDept;

//     // Create Energy and Water Resources
//     Energy *energyResource = new Energy();
//     Water *waterResource = new Water();

//     std::cout << "\n--- Create Utilities ---\n";
//     ProductionUtility *powerPlant = new PowerPlant("CityPower", resourceDept, energyResource);
//     ProductionUtility *waterSupply = new WaterSupply("CityWater", resourceDept, waterResource);
//     ServiceUtility *wasteManagement = new WasteManagement("CityWaste", resourceDept);
//     ServiceUtility *sewerSystem = new SewageSystem("CitySewage", resourceDept);

//     // Start in Operational State for both utilities
//     std::cout << "\n--- Start Production ---\n";
//     powerPlant->startProduction();
//     powerPlant->startProduction();

//     // waterSupply->startProduction();
//     // waterSupply->startProduction();

//     std::cout << "\n--- Start Service ---\n";
//     wasteManagement->startService();
//     // wasteManagement->startService();

//     // sewerSystem->startService();
//     // sewerSystem->startService();
// }

// int main()
// {

//     simulationOne();

//     return 0;
// }
