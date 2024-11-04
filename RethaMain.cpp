// #include "Main.h"
// // DECLARING GLOBAL VARIABLES
// Government *Gov;
// HealthcareFacility *clinic, *GH, *ICH;
// Resources *WaterResource, *EnergyResource;
// Population *AdultFactory, *MinorFactory;
// ProductionUtility *powerPlant, *waterSupply;
// ServiceUtility *wasteManagement, *SewerSystem;
// Department *DevDept, *FinDept, *SoAffDept, *TransDept, *ResourceDept, *healthDept;
// TaxCalculator *taxes[6];
// WiseBucks *apps[6];

// void governmentObjects()
// {

//     Gov = Government::getInstance();
//     ResourceDept = new ResourceDepartment(100000);
//     Gov->addDepartment("Resources", ResourceDept);
//     ResourceDepartment *resDept = dynamic_cast<ResourceDepartment *>(Gov->getDepartment("Resources"));
//     FinDept = new FinanceDept(100000);
//     Gov->addDepartment("Finance", FinDept);
//     DevDept = new DevelopmentDept(1000000, resDept);
//     Gov->addDepartment("Development", DevDept);
//     // TransDept = new TransportDept(100000);
//     // Gov->addDepartment("Transport", TransDept(100000));
//     healthDept = new HealthDept(50000);
//     Gov->addDepartment("Health", healthDept);
//     SoAffDept = new SocialAffairsDept(100000);
//     Gov->addDepartment("SocialAffairs", SoAffDept);
// }

// void utilResourceObjects()
// {

//     EnergyResource = new Energy();
//     WaterResource = new Water();

//     powerPlant = new PowerPlant("CityPower", static_cast<ResourceDepartment *>(ResourceDept), static_cast<Energy *>(EnergyResource), 20);
//     waterSupply = new WaterSupply("CityWater", static_cast<ResourceDepartment *>(ResourceDept), static_cast<Water *>(WaterResource), 20);
//     wasteManagement = new WasteManagement("CityWaste", static_cast<ResourceDepartment *>(ResourceDept));
//     SewerSystem = new SewageSystem("CitySewage", static_cast<ResourceDepartment *>(ResourceDept));

//     ((ResourceDepartment *)ResourceDept)->addUtility(powerPlant);
//     ((ResourceDepartment *)ResourceDept)->addUtility(waterSupply);
//     ((ResourceDepartment *)ResourceDept)->addUtility(wasteManagement);
//     ((ResourceDepartment *)ResourceDept)->addUtility(SewerSystem);
//     // Start in Operational State for both utilities
//     // std::cout << "\n--- Start Production ---\n";
//     // powerPlant->startProduction();
//     // powerPlant->startProduction();

//     // waterSupply->startProduction();
//     // waterSupply->startProduction();

//     // std::cout << "\n--- Start Service ---\n";
//     // wasteManagement->startService();
//     // wasteManagement->startService();

//     // SewerSystem->startService();
//     // SewerSystem->startService();
// }

// void citizenObjects()
// {
//     AdultFactory = new AdultPop();
//     MinorFactory = new MinorPop();
// }

// int main()
// {

//     governmentObjects();

//     citizenObjects();
//     Citizen **first100 = AdultFactory->reproduce(100);
//     {
//         for (int i = 0; i < 100; i++)
//         {
//             ((Adult *)first100[i])->setHouse(((DevelopmentDept *)(Gov->getDepartment("Development")))->build("House"));
//             ((SocialAffairsDept *)(Gov->getDepartment("SocialAffairs")))->addCitizen(first100[i]);
//             ((SocialAffairsDept *)(Gov->getDepartment("SocialAffairs")))->addToUnemployed(first100[i]);
//         }
//     }
//     utilResourceObjects();
//     return 0;
// }
