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
// #include "Water.h"
// #include "Energy.h"
// #include "Materials.h"
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
//     std::cout << "Simulation One" << std::endl;
//     // Create Resource Department
//     ResourceDepartment *ResourceDept;
//     Resources *WaterResource, *EnergyResource;
//     ProductionUtility *powerPlant, *waterSupply;
//     ServiceUtility *wasteManagement, *SewerSystem;
//     EnergyResource = new Energy();
//     WaterResource = new Water();
   
//     std::cout << "Simulation One" << std::endl;
//     powerPlant = new PowerPlant("CityPower", static_cast<ResourceDepartment *>(ResourceDept), static_cast<Energy *>(EnergyResource), 20);
//     std::cout << "Simulation One" << std::endl;
//     waterSupply = new WaterSupply("CityWater", static_cast<ResourceDepartment *>(ResourceDept), static_cast<Water *>(WaterResource), 20);
//     std::cout << "Simulation One" << std::endl;
//     wasteManagement = new WasteManagement("CityWaste", static_cast<ResourceDepartment *>(ResourceDept));
//     SewerSystem = new SewageSystem("CitySewage", static_cast<ResourceDepartment *>(ResourceDept));

//     // retha's main

//     // Start in Operational State for both utilities
//     std::cout << "\n--- Start Production ---\n";
//     powerPlant->startProduction();
//     powerPlant->startProduction();

//     waterSupply->startProduction();
//     waterSupply->startProduction();

//     std::cout << "\n--- Start Service ---\n";
//     wasteManagement->startService();
//     wasteManagement->startService();

//     SewerSystem->startService();
//     SewerSystem->startService();
// }


// int main()
// {

//     simulationOne();

//     return 0;
// }
