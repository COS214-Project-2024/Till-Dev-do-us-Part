// #include "Main.h"

// // SIMULATION DISPLAY
// #include "display.h"

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

// // Add funtion in goverment to get overall status of the city. MyCityStatus();
// void DemoMain();

// void governmentObjects();
// void utilResourceObjects();
// void buildingObjects();
// void financeObjects();
// void transportObjects();

// void healthcareObjects();
// void citizenObjects();

// // SIMULATION

// void performDailyActivities();
// void inflation();
// void unleashDisease();
// void strike();

// // SEASON METHODS
// // Create a loop that runs 3 times in each season
// void summer(); // Use more money
// void autumn(); // More businesses opening
// void winter(); // use up more utilities, more consumption
// void spring(); // More babies, September babies

// void globalCleanUp();

// std::map<int, std::string> monthsOfTheYear = {
//     {1, "January"},
//     {2, "February"},
//     {3, "March"},
//     {4, "April"},
//     {5, "May"},
//     {6, "June"},
//     {7, "July"},
//     {8, "August"},
//     {9, "September"},
//     {10, "October"},
//     {11, "November"},

//     {12, "December"}};

// int main()
// {
// #ifdef _WIN32
//     // Enable ANSI escape sequences for Windows
//     system("color");
// #endif
//     DemoMain();
//     return 0;
// }

// void DemoMain()
// {
//     cout << "===========================================================================================================================================================================" << endl;

//     // cout << "  WELCOME TO THE GREATEST CITY IN 214" << endl;
//     // cout << "~ created by TDP - Till Dev do us Part ~" << endl;

//     // displayIntro();
//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Creating Goverment and its Departments:" << endl;
//     governmentObjects();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Gathering resources and creating Utility plants..." << endl;
//     utilResourceObjects();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Setting up tax collection via the WiseBucksApp" << endl;
//     financeObjects();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Building parks, monuments and cultural centers" << endl;
//     buildingObjects();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Building roads, train stations, railways and transport modes..." << endl;
//     transportObjects();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Setting up healthcare facilities" << endl;
//     healthcareObjects();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Appearance of the first 100 citizens" << endl;
//     citizenObjects();
//     Citizen **first100 = AdultFactory->reproduce(100);
//     {
//         for (int i = 0; i < 100; i++)
//         {
//             ((Adult*) first100[i])->setHouse(((DevelopmentDept*)(Gov->getDepartment("Development")))->build("House")); 
//             ((SocialAffairsDept *)(Gov->getDepartment("SocialAffairs")))->addCitizen(first100[i]); 
//             ((SocialAffairsDept *)(Gov->getDepartment("SocialAffairs")))->addToUnemployed(first100[i]);
//         }

//     }

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Creating businesses to get the economy going..." << endl;

//     Business *first8Businesses[8];

//     {
//         first8Businesses[0] = new Automotive();
//         first8Businesses[1] = new Consulting();
//         first8Businesses[2] = new Entertainment();
//         first8Businesses[3] = new Food();
//         first8Businesses[4] = new Hospitality();
//         first8Businesses[5] = new Retail();
//         first8Businesses[6] = new Technology();
//         first8Businesses[7] = new Wellness();

//         first8Businesses[0]->linkWiseBucks(apps[3]);
//         first8Businesses[1]->linkWiseBucks(apps[2]);
//         first8Businesses[2]->linkWiseBucks(apps[2]);
//         first8Businesses[3]->linkWiseBucks(apps[1]);
//         first8Businesses[4]->linkWiseBucks(apps[1]);
//         first8Businesses[5]->linkWiseBucks(apps[5]);
//         first8Businesses[6]->linkWiseBucks(apps[1]);
//         first8Businesses[7]->linkWiseBucks(apps[2]);

//         for (Business *business : ((FinanceDept *)(Government::getInstance()->getDepartment("Finance")))->getBusinesses())
//         {
//             // NOT DESTRUCTED
//             business->buyProperty("Shop");
//         }

//         for (int i = 0; i < 8; i++)
//         {
//             for (int j = 0; j < 5; j++)
//             {
//                 first8Businesses[i]->hireEmployee();
//             }
//         }

//     }

//     cout << "===========================================================================================================================================================================" << endl;
//     // Season and day simulation
//     {
//         std::string currentSeason = "";

//         for (int month = 1; month <= 12; ++month)
//         {

//             std::cout << endl;

//             // Determine the season based on the month
//             if (month >= 3 && month <= 5)
//             {
//                 if (currentSeason != "Spring")
//                 {

//                     cout << "===========================================================================================================================================================================" << endl;
//                     autumn();
//                     std::cout << endl;
//                     currentSeason = "Spring";
//                 }
//             }
//             else if (month >= 6 && month <= 8)
//             {
//                 if (currentSeason != "Summer")
//                 {

//                     cout << "===========================================================================================================================================================================" << endl;
//                     winter();
//                     std::cout << endl;
//                     currentSeason = "Summer";
//                 }
//             }
//             else if (month >= 9 && month <= 11)
//             {
//                 if (currentSeason != "Autumn")
//                 {

//                     cout << "===========================================================================================================================================================================" << endl;
//                     spring();
//                     std::cout << endl;
//                     currentSeason = "Autumn";
//                 }
//             }
//             else
//             {
//                 if (currentSeason != "Winter")
//                 {

//                     cout << "===========================================================================================================================================================================" << endl;
//                     summer();
//                     if (monthsOfTheYear[month] == "December")
//                     {
//                         cout << " again";
//                     }
//                     cout << "! " << endl
//                          << endl;

//                     currentSeason = "Winter";
//                 }
//             }

//             cout << monthsOfTheYear[month] << "\n";
//             cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
//             this_thread::sleep_for(chrono::milliseconds(5000));
//         }
//     }

//     cout << "===========================================================================================================================================================================" << endl;

//     // DELETES

//     for (int i = 0; i < 8; i++)
//     {
//         delete first8Businesses[i];
//         first8Businesses[i] = nullptr;
//     }

//     delete[] first100;
//     first100 = nullptr;

// }

// void performDailyActivities()
// {
//     ((SocialAffairsDept *)(Gov->getDepartment("SocialAffairs")))->sendAdultsToWork();
//     ((FinanceDept *)(Government::getInstance()->getDepartment("Finance")))->getCRS()->settleTax(); 
// }

// void unleashDisease(){

// }

// void governmentObjects()
// {

//     Gov = Government::getInstance();
//     ResourceDept = new ResourceDepartment(100000);
//     Gov->addDepartment("Resources", ResourceDept);
//     FinDept = new FinanceDept(100000);
//     Gov->addDepartment("Finance", FinDept);
//     DevDept = new DevelopmentDept(1000000);
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

//     // retha's main

//     // Start in Operational State for both utilities
//     std::cout << "\n--- Start Production ---\n";
//     powerPlant->startProduction();
//     powerPlant->startProduction();

//     // waterSupply->startProduction();
//     // waterSupply->startProduction();

//     // std::cout << "\n--- Start Service ---\n";
//     // wasteManagement->startService();
//     // wasteManagement->startService();

//     // SewerSystem->startService();
//     // SewerSystem->startService();
// }

// void buildingObjects()
// {
//     // Implementation required
// }

// void financeObjects()
// {
//     taxes[0] = new CorporateTax();
//     taxes[1] = new Customs();
//     taxes[2] = new IncomeTax();
//     taxes[3] = new PAYE();
//     taxes[4] = new PropertyRates();
//     taxes[5] = new VAT();

//     apps[0] = new WiseBucks(taxes[0]);
//     apps[1] = new WiseBucks(taxes[1]);
//     apps[2] = new WiseBucks(taxes[2]);
//     apps[3] = new WiseBucks(taxes[3]);
//     apps[4] = new WiseBucks(taxes[4]);
//     apps[5] = new WiseBucks(taxes[5]);
// }

// void transportObjects()
// {
//     // Implementation required
// }

// void healthcareObjects()
// {

//     clinic = new Clinic();
//     GH = new Hospital1();
//     ICH = new Hospital2();

//     ((HealthDept *)(Gov->getDepartment("Health")))->addFacility("Clinic", clinic);
//     ((HealthDept *)(Gov->getDepartment("Health")))->addFacility("General Hospital", GH);
//     ((HealthDept *)(Gov->getDepartment("Health")))->addFacility("Intensive Care Hospital", ICH);
// }

// void citizenObjects()
// {
//     AdultFactory = new AdultPop();
//     MinorFactory = new MinorPop();
// }

// void summer()
// {
//     cout << "Summer has arrived";

//     for(int i=0; i<10; i++){
//         performDailyActivities();
//     }
// }

// void autumn()
// {
//     cout << "Autumn has arrived! " << endl;
//     performDailyActivities();
// }

// void winter()
// {
//     cout << "Winter has arrived! " << endl;
//     performDailyActivities();
//     // unleashDisease();
// }

// void spring()
// {
//     cout << "Spring has arrived! " << endl;
//     performDailyActivities();
//     ((SocialAffairsDept *)(Gov->getDepartment("SocialAffairs")))->growPopulation(100);

// }

// void globalCleanUp()
// {

//     for (int i = 0; i < 6; i++)
//     {
//         delete apps[i];
//         apps[i] = nullptr;
//     }

//     for (int i = 0; i < 6; i++)
//     {
//         delete taxes[i];
//         taxes[i] = nullptr;
//     }

//     delete MinorFactory;
//     MinorFactory = nullptr;

//     delete AdultFactory;
//     AdultFactory = nullptr;

//     delete ICH;
//     ICH = nullptr;

//     delete GH;
//     GH = nullptr;

//     delete clinic;
//     clinic = nullptr;

//     delete WaterResource;
//     WaterResource = nullptr;

//     delete EnergyResource;
//     EnergyResource = nullptr;

//     Gov->removeDepartment("SocialAffairs");
//     delete SoAffDept;
//     SoAffDept = nullptr;

//     Gov->removeDepartment("Health");
//     delete healthDept;
//     healthDept = nullptr;

//     Gov->removeDepartment("Transport");
//     delete TransDept;
//     TransDept = nullptr;

//     delete ICH;
//     ICH = nullptr;

//     delete GH;
//     GH = nullptr;

//     delete clinic;
//     clinic = nullptr;

//     delete WaterResource;
//     WaterResource = nullptr;

//     delete EnergyResource;
//     EnergyResource = nullptr;

//     Gov->removeDepartment("SocialAffairs");
//     delete SoAffDept;
//     SoAffDept = nullptr;

//     Gov->removeDepartment("Health");
//     delete healthDept;
//     healthDept = nullptr;

//     Gov->removeDepartment("Transport");
//     delete TransDept;
//     TransDept = nullptr;

//     Gov->removeDepartment("Development");
//     delete DevDept;
//     DevDept = nullptr;

//     Gov->removeDepartment("Finance");
//     delete FinDept;
//     FinDept = nullptr;

//     Gov->removeDepartment("Resources");
//     delete ResourceDept;
//     ResourceDept = nullptr;

//     delete Gov;
//     Gov = nullptr;
// }
