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

// void simulationOne()  //RETHABILE
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

void simulationtwo() //THENDO
{
    // Create Resource Department
    // ResourceDepartment* resourceDept;

    // // // Create Energy and Water Resources
    // Resources *energyResource = new Energy();
    // Water waterResource;

    // // Create PowerPlant and WaterSupply objects
    // PowerPlant *powerPlant = new PowerPlant("CityPower", resourceDept, energyResource);
    // WaterSupply waterSupply();

    // // Create Production States
    // // OperationalProductionState operationalState;
    // // MaintenanceProductionState maintenanceState;
    // // OutageProductionState outageState;

    // // Start in Operational State for both utilities
    // std::cout << "\n--- Starting Production in Operational State ---\n";
    // cout<<powerPlant->getResource()<<endl;
    // powerPlant->startProduction()<<endl;
    // energyResource->consume(800);
    //powerPlant->
    //waterSupply.setProductionState(&operationalState);

    // powerPlant.startProduction();
    // waterSupply.startProduction();

    // // Transition to Maintenance State
    // std::cout << "\n--- Switching to Maintenance State ---\n";
    // powerPlant.setProductionState(&maintenanceState);
    // waterSupply.setProductionState(&maintenanceState);

    // powerPlant.startProduction();
    // waterSupply.startProduction();

    // // Transition to Outage State
    // std::cout << "\n--- Switching to Outage State ---\n";
    // powerPlant.setProductionState(&outageState);
    // waterSupply.setProductionState(&outageState);

    // powerPlant.startProduction();
    // waterSupply.startProduction();

    //    Water waterResource;
    // Materials materialsResource("WOOD");
    // Energy energyResource;

    // ResourceDepartment *resDept = new ResourceDepartment();
    // Use Utility to hold each type
//    Utility waterUtil("Water Utility", resDept, &waterResource, 10);
//     Utility materialsUtil("Materials Utility", resDept, &materialsResource, 15);
//     Utility energyUtil("Energy Utility", resDept, &energyResource, 20);

//     // Get and display the type of resource
//     std::cout << "Resource type: " << waterUtil.getResource()->getName() << std::endl; // Output: Water
//     std::cout << "Resource type: " << materialsUtil.getResource()->getName() << std::endl; // Output: Materials
//     std::cout << "Resource type: " << energyUtil.getResource()->getName() << std::endl; // Output: Energy



//  ServiceUtility wasteManagement("waste management",resDept,&materialsResource,10,100);

// cout<<wasteManagement.



  //ServiceUtility wasteManagement()


// int main()
// {
//     // Call the simulation
//     return 0;
// }

// void simulation()
// {
//     Water water();      // Example initial amount of water
//     Energy energy();    // Example initial amount of energy
//     Materials materials("Wood"); // Example initial materials with quantity

//     // Initialize ResourceDepartment and add utilities
//     ResourceDepartment resourceDept;
//     resourceDept.addUtility(Utility* PowerPlant("Water Utility", resDept, &waterResource, 10));
//         //new WaterSupply(water));
//     //resourceDept.addUtility(new PowerPlant(energy));
//     resourceDept.addUtility(new WasteManagement());
//     resourceDept.addUtility(new SewageSystem());

//     // Initialize Controller and set initial states
//     Controller controller;
//     controller.setState(new ProOperationalState());

//     // Initialize other essential variables
//     bool running = true;
//     int simulationTime = 10; // Define how long the simulation will run
//     int timeStep = 1;        // Time step in seconds for each simulation iteration

//     std::cout << "Starting city utility simulation..." << std::endl;

//     // Main simulation loop
//     for (int time = 0; time < simulationTime; ++time) {
//         std::cout << "Time step: " << time << std::endl;

//         // Process resource requests for each utility in ResourceDepartment
//         resourceDept.processResourceRequest();

//         // Check resource levels and update state if necessary
//         if (water.getAvailableQuantity() < 100.0f) {
//             std::cout << "Water levels are low. Switching to ProMaintenanceState for Water Supply." << std::endl;
//             controller.setState(new ProMaintenanceState());
//         }
        
//         if (energy.getAvailableQuantity() < 500.0f) {
//             std::cout << "Energy levels are critical. Power plant going to ProOutageState." << std::endl;
//             controller.setState(new ProOutageState());
//         }

//         // Simulate utility production and service
//         for (auto utility : resourceDept.getUtilities()) {
//             utility->startProduction();
//             utility->serviceProduction();
//         }

//         // Display current resource status
//         std::cout << "Current water level: " << water.getAvailableQuantity() << std::endl;
//         std::cout << "Current energy level: " << energy.getAvailableQuantity() << std::endl;
//         std::cout << "Current materials quantity: " << materials.getQuantity() << std::endl;}
// }



    // Create a ResourceDepartment
    // ResourceDepartment resourceDept;

    // // Initialize resources
    // Water* waterResource= new Water();  // Initial amount of 10,000 liters of water
    // Energy* energyResource= new Energy(); // Initial amount of 5,000 kWh of energy
    // Materials* materialsResource= new Materials("Steel"); // Initial amount of 2,000 units of materials


    //   PowerPlant* powerPlant=new PowerPlant("Main Power Plant", &resourceDept, energyResource);

    //Create Utilities
    // Utility* waterUtility= new Utility("Water Utility",&resourceDept, waterResource, 20);
    // Utility* energyUtility = new Utility("Energy Utility", &resourceDept, energyResource, 15);
    // Utility* materialsUtility = new Utility("Materials Utility", &resourceDept, materialsResource, 10);


    //Add utilities to ResourceDepartment
    //resourceDept.addUtility(powerPlant);
   // powerPlant->startProduction();
    // resourceDept.addUtility(energyUtility);
    // resourceDept.addUtility(materialsUtility);

    // // // Simulate operation
    // std::cout << "\n--- Simulation Start ---\n" << std::endl;
    // for (int day = 1; day <= 5; ++day) { // Simulate for 5 days
    //     std::cout << "Day " << day << std::endl;

        // Each utility checks for breakdowns
        // waterUtility->checkForBreakdowns();
        // energyUtility->checkForBreakdowns();
        // materialsUtility->checkForBreakdowns();

        // // Print utility statuses
        // std::cout << waterUtility->getStatus() << std::endl;
        // std::cout << energyUtility->getStatus() << std::endl;
        // std::cout << materialsUtility->getStatus() << std::endl;

        // // Consume resources (you can expand this based on your specific requirements)
        // waterResource->consume(500);  // Consume 500 units of water daily
        // energyResource->consume(300); // Consume 300 units of energy daily
        // materialsResource->consume(100); // Consume 100 units of materials daily

        // std::cout << "\nResource status:" << std::endl;
        // std::cout << "Water remaining: " << waterResource->getCurrentAmount() << std::endl;
        // std::cout << "Energy remaining: " << energyResource->getCurrentAmount() << std::endl;
        // std::cout << "Materials remaining: " << materialsResource->getCurrentAmount() << std::endl;

        // std::cout << "\n--- End of Day " << day << " ---\n" << std::endl;}
    

    // Output current status
   // std::cout << powerPlant->getStatus() << std::endl;
    // std::cout << "Current Energy after operation: " << energyResource->getCurrentAmount() << " units\n";
    // // Clean up dynamic memory
    //        delete waterResource;
    //     delete energyResource;
    //     delete materialsResource;


    // delete waterUtility;
    // delete energyUtility;
    // delete materialsUtility;




    // Create resources
    //     Water* water = new Water();
    //     Energy* energy = new Energy();
    //     Materials* steel = new Materials("Steel");
    //     Materials* wood = new Materials("Wood");

    //      // Test different scenarios
    //     cout << "--- Testing Water Resource ---" << endl;
    //      cout<<water->getState()<<endl;
    //     water->consume(18000);
    //     water->consume(40000);
    //     water->consume(40000);

    //     cout << "\n--- Testing Energy Resource ---" << endl;
    //     energy->consume(100002);
    //     energy->consume(800);

    //    cout << "\n--- Testing Other Resources ---" << endl;
    //    cout<<"Steel's state: "<<steel->getState()<<endl;
    //    cout<<"Wood's state: "<<wood->getState()<<endl;

    //     // Cleanup
    //     delete water;
    //     delete energy;
    //     delete steel;
    //     delete wood;
    //simulationOne();

}

int main()
{
    // Create resources
    //     Water* water = new Water();
    //     Energy* energy = new Energy();
    //     Materials* steel = new Materials("Steel");
    //     Materials* wood = new Materials("Wood");

    //      // Test different scenarios
    //     cout << "--- Testing Water Resource ---" << endl;
    //      cout<<water->getState()<<endl;
    //     water->consume(18000);
    //     water->consume(40000);
    //     water->consume(40000);

    //     cout << "\n--- Testing Energy Resource ---" << endl;
    //     energy->consume(100002);
    //     energy->consume(800);

    //    cout << "\n--- Testing Other Resources ---" << endl;
    //    cout<<"Steel's state: "<<steel->getState()<<endl;
    //    cout<<"Wood's state: "<<wood->getState()<<endl;

    //     // Cleanup
    //     delete water;
    //     delete energy;
    //     delete steel;
    //     delete wood;
    simulationtwo();

        return 0;
}
