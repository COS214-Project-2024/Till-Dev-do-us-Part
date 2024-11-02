
//     #include "Resources.h"
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
// #include "ServiceUtility.h"
// #include "Utility.h"


// void testingResources()
// {

// // Create resources
//         Resources* water = new Water();
//        Resources* energy = new Energy();
//         Resources* steel = new Materials("Steel");
//         Resources* wood = new Materials("Wood");

//          // Test different scenarios
//         cout << "--- Testing Water Resource ---" << endl;
//          cout<<water->getState()<<endl;
//         water->consume(000);
//         water->consume(40000);
//          water->consume(40000);
//           water->consume(1000);

//         cout << "\n--- Testing Energy Resource ---" << endl;
//         energy->consume(100002);
//         energy->consume(800);

//        cout << "\n--- Testing Other Resources ---" << endl;
//        cout<<"Steel's state: "<<steel->getState()<<endl;
//        cout<<"Wood's state: "<<wood->getState()<<endl;
//         cout<<"energy's state: "<<energy->getState()<<endl;
//        cout<<"water's state: "<<water->getState()<<endl;

//     //     // Cleanup
//     //     delete water;
//          delete energy;
//         delete steel;
//         delete wood;
// }
// int main()
// {
    
//     testingResources();

//         return 0;
// }



#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest/doctest.h"

#include "Resources.h"
#include "Water.h"
#include "Energy.h"
#include "Materials.h"

#include <iostream>
#include <memory>

TEST_CASE("Resource Consumption and State Testing") {
    SUBCASE("Water Resource Consumption") {
        Water water;
        
        // Initial state check
        CHECK(water.getState() == "Surplus State");
        
        // Consume small amount
        water.consume(0);
        CHECK(water.getState() == "Surplus State");
        
        // Consume moderate amount
        water.consume(40000);
        CHECK(water.getState() == "Balanced State");
        
        // Consume again
        water.consume(40000);
        CHECK(water.getState() == "Critical State");
        
        // Consume small amount in critical state
        water.consume(1000);
        CHECK(water.getState() == "Surplus State");
    }
    
    SUBCASE("Energy Resource Consumption") {
        Energy energy;
        
        CHECK(energy.getInitialAmount()==100000);
        // Initial state check
        CHECK(energy.getState() == "Surplus State");
        
        // Consume large amount
        energy.consume(100002);
        CHECK(energy.getState() == "Surplus State");
        
        // Consume small amount
        energy.consume(800);
        CHECK(energy.getState() == "Balanced State");

         CHECK(energy.getCurrentAmount()==99200);

    }
    
    SUBCASE("Materials Resource State") {
        Materials steel("Steel");
        Materials wood("Wood");
        
        // Check initial states
        CHECK(steel.getState() == "Surplus State");
        CHECK(wood.getState() == "Surplus State");
        
        // Verify material names
        CHECK(steel.getName() == "Material-Steel");
        CHECK(wood.getName() == "Material-Wood");
    }
}

// Optional: Additional specific tests for each resource type
TEST_CASE("Specific Resource Type Checks") 
{
    SUBCASE("Water Specific Tests") 
    {
        Water water;
        water.consume(50000);
        CHECK(water.getState() == "Balanced State");
       
        CHECK(water.getName()=="Water");
    }
    
    SUBCASE("Energy Specific Tests") 
    {
        Energy energy;
        energy.consume(200000);
        CHECK_NE(energy.getCurrentAmount(),10000.0);
        CHECK(energy.getAvailableQuantity()==100000);
        CHECK(energy.getName()=="Energy");
        CHECK(energy.getState() == "Surplus State");
    }
}