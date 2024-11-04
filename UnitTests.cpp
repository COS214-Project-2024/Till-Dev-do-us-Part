#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "House.h"
#include "Adult.h"
#include "Citizen.h"
#include "DilapidatedState.h"
#include "DilapidatedState.h"
#include "ResourceDepartment.h"
#include "Water.h"
#include "Energy.h"

TEST_CASE("Testing House class")
{
    Department* resDept = new ResourceDepartment(10000);
    ((ResourceDepartment*)resDept)->addResource(new Water());
    ((ResourceDepartment*)resDept)->addResource(new Energy());
    DevelopmentDept* dept = new DevelopmentDept(10000, (ResourceDepartment*)resDept);
    Building* house = dept->build("House");
    Citizen* c = new Adult();

    SUBCASE("Default initialization")
    {
        CHECK(house->useElectricity(100) == 0); // Assuming initial cleanliness is 100
        CHECK(house->useWater(100) == 0); // Assuming initial cleanliness is 100
        CHECK(house->getValue() == 1000);      // Assuming getter exists
        CHECK(house->getType() == "House");      // Assuming getter exists
        CHECK(house->getWater() == 0); // Assuming initial cleanliness is 100
        CHECK(house->getElectricity() == 0); // Assuming initial cleanliness is 100
        CHECK(house->getCleanliness() == 100); // Assuming initial cleanliness is 100
        house->demolish(); // Assuming initial cleanliness is 100
        CHECK(house->clean() == false); // Assuming initial cleanliness is 100
        CHECK(house->clone()->getType() == "House"); // Assuming initial cleanliness is 100
        CHECK(house->isOccupied() == false); // Assuming initial cleanliness is 100
        CHECK(house->getState() == "Construction"); // Assuming initial cleanliness is 100
        
    }

    SUBCASE("Testing with citizen")
    {
        ((Adult*)c)->setHouse(house);
        ((Adult*)c)->goToWork();

        CHECK(house->getWater() == 904);                  // Assuming initial cleanliness is 100
        CHECK(house->getElectricity() == 915);            // Assuming initial cleanliness is 100
        CHECK(house->getCleanliness() == 61);          // Assuming initial cleanliness is 100

    }

    }
