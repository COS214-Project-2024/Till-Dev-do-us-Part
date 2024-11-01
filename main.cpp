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

// void simulationOne()
// {
//     // Create Resource Department
//     ResourceDepartment *resourceDept;

//     // Create Energy and Water Resources
//     Resources *energyResource = new Energy();
//     Water waterResource;

//     // Create PowerPlant and WaterSupply objects
//     Utility *powerPlant = new PowerPlant("CityPower", resourceDept, energyResource);
//     ProductionUtility *waterSupply = new WaterSupply("CityWater", resourceDept, energyResource);
//     // Create Production States
//     OperationalProductionState *operationalState = new OperationalProductionState();
//     MaintenanceProductionState *maintenanceState;
//     OutageProductionState *outageState;

//     // Start in Operational State for both utilities
//     std::cout << "\n--- Starting Production in Operational State ---\n";
//     powerPlant->
//     waterSupply->
   

//     powerPlant.startProduction();
//     waterSupply.startProduction();

//     // Transition to Maintenance State
//     std::cout << "\n--- Switching to Maintenance State ---\n";
//     powerPlant.setProductionState(&maintenanceState);
//     waterSupply.setProductionState(&maintenanceState);

//     powerPlant.startProduction();
//     waterSupply.startProduction();

//     // Transition to Outage State
//     std::cout << "\n--- Switching to Outage State ---\n";
//     powerPlant.setProductionState(&outageState);
//     waterSupply.setProductionState(&outageState);

//     powerPlant.startProduction();
//     waterSupply.startProduction();
// }



// int main()
// {
//     // Create resources
//     //     Water* water = new Water();
//     //     Energy* energy = new Energy();
//     //     Materials* steel = new Materials("Steel");
//     //     Materials* wood = new Materials("Wood");

//     //      // Test different scenarios
//     //     cout << "--- Testing Water Resource ---" << endl;
//     //      cout<<water->getState()<<endl;
//     //     water->consume(18000);
//     //     water->consume(40000);
//     //     water->consume(40000);

//     //     cout << "\n--- Testing Energy Resource ---" << endl;
//     //     energy->consume(100002);
//     //     energy->consume(800);

//     //    cout << "\n--- Testing Other Resources ---" << endl;
//     //    cout<<"Steel's state: "<<steel->getState()<<endl;
//     //    cout<<"Wood's state: "<<wood->getState()<<endl;

//     //     // Cleanup
//     //     delete water;
//     //     delete energy;
//     //     delete steel;
//     //     delete wood;
//     simulationOne();

//         return 0;
// }
