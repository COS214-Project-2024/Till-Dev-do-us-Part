// //INCLUDES:
// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest/doctest/doctest.h"

// //BOITUMELO MTSATSE


// //DRIYA GOVENDER


// //KARABO SEROTHOANE


// //KATLEGO MOSITI


// //PABALLO DIYASE


// //RETHABILE BORE


// //THENDO MBEDZI

// #include "Resources.h"
// #include "Water.h"
// #include "Energy.h"
// #include "Materials.h"

// TEST_SUITE("Resource Management System Tests") {
//     TEST_CASE("Water Resource Tests") {
//         Water* water = new Water();
        
//         SUBCASE("Initial State") {
//             CHECK(water->getName() == "Water");
//             CHECK(water->getState() == "Surplus State");
//             CHECK(water->getInitialAmount() == 100000);
//         }
        
//         SUBCASE("First Consumption") {
//             water->consume(18000);
//             CHECK(water->getState() == "Balanced State" );
//         }
        
//         SUBCASE("second State") {
//             water->consume(40000);
//             CHECK(water->getState() == "Balanced State");
//         }
        
//         SUBCASE("Critical State") {
//             water->consume(40000);
//             water->consume(40000);
//             CHECK(water->getState() == "Critical State");
//         }
        
//         SUBCASE("Resource Tracking") {
//             water->consume(1000);
//             CHECK_NOTHROW(water->trackResources());
//         }
        
//         delete water;
//     }

//     TEST_CASE("Energy Resource Tests") {
//         Energy* energy = new Energy();
        
//         SUBCASE("Initial State") {
//             CHECK(energy->getName() == "Energy");
//             CHECK(energy->getState() == "Surplus State");
//             CHECK(energy->getInitialAmount() == 100000);
//         }
        
//         SUBCASE("Large Consumption") {
//             energy->consume(100002);
//             CHECK(energy->getState() == "Surplus State");
//         }
        
//         SUBCASE("Small Consumption") {
//             energy->consume(800);
//             CHECK(energy->getState() == "Balanced State");
//         }
        
//         SUBCASE("Resource Tracking") {
//             energy->consume(1000);
//             CHECK_NOTHROW(energy->trackResources());
//         }
        
//         delete energy;
//     }

//     TEST_CASE("Materials Resource Tests") {
//         Materials* steel = new Materials("Steel");
//         Materials* wood = new Materials("Wood");
        
//         SUBCASE("Initial States") {
//             CHECK(steel->getName() == "Material-Steel");
//             CHECK(wood->getName() == "Material-Wood");
//             CHECK(steel->getState() == "Surplus State");
//             CHECK(wood->getState() == "Surplus State");
//         }
        
//         SUBCASE("Consumption Patterns") {
//             steel->consume(5000);
//             wood->consume(3000);
//             CHECK(steel->getState() == "Balanced State");
//             CHECK(wood->getState() == "Balanced State");
//         }
        
//         delete steel;
//         delete wood;
//     }

//     TEST_CASE("Edge Cases") {
//         Water* water = new Water();
        
//         SUBCASE("Zero Consumption") {
//             water->consume(0);
//             CHECK(water->getState() == "Surplus State");
//         }
        
//         SUBCASE("Very Small Consumption") {
//             water->consume(1);
//             CHECK(water->getState() == "Balanced State");
//         }
        
//         SUBCASE("Very Large Consumption") {
//             water->consume(999999);
//             CHECK(water->getState() == "Surplus State");
//         }
        
//         delete water;
//     }
// }