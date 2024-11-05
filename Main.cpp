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
// Business *first8Businesses[8];
// Citizen **first100;
// Citizen **morePeople;

// // Add funtion in goverment to get overall status of the city. MyCityStatus();
// void DemoMain();

// void governmentObjects();
// void utilResourceObjects();
// void buildingObjects();
// void financeObjects();
// void transportObjects();
// void createBusinesses(); 
// void healthcareObjects();
// void citizenObjects();

// // SIMULATION

// void performDailyActivities();
// void inflation();
// void unleashDisease();
// void strike();
// void simulation(); 

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

//     displayIntro();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Appearance of the first 150 citizens..." << endl;

//     cout << "===========================================================================================================================================================================" << endl;
    
//     cout << "Creating Goverment and its Departments..." << endl;
//     governmentObjects();

//     citizenObjects();
//     first100 = AdultFactory->reproduce(50);

//     for (int i = 0; i < 50; i++)
//     {
//         ((Adult *)first100[i])->setHouse(((DevelopmentDept *)(Gov->getDepartment("Development")))->build("House"));
//         ((SocialAffairsDept *)(Gov->getDepartment("SocialAffairs")))->addCitizen(first100[i]);
//         ((SocialAffairsDept *)(Gov->getDepartment("SocialAffairs")))->addToUnemployed(first100[i]);
//     }

//     morePeople = AdultFactory->reproduce(200);

//     for (int j = 0; j < 50; j++){

//         Building* h = ((Adult*)first100[j])->getHouse();
//         int num = 0;

//         for (int i = 0; i < 200; i++)
//         {
//             if(num<5 && !((Adult*)morePeople[i])->hasHouse()){
//                 ((Adult*)morePeople[i])->setHouse(h);
//                 h->addOccupant(morePeople[i]);
//                 num++;
//             }
//             else
//                 continue;
//         }
//     }

//     simulation(); 

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Gathering resources and creating utility plants..." << endl;
//     utilResourceObjects();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Setting up tax collection via the WiseBucksApp..." << endl;
//     financeObjects();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Building parks, monuments and cultural centers..." << endl;
//     buildingObjects();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Building roads, train stations, railways and transport modes..." << endl;
//     transportObjects();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Setting up healthcare facilities..." << endl;
//     healthcareObjects();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Creating businesses to get the economy going..." << endl;
//     createBusinesses(); 

//     cout << "===========================================================================================================================================================================" << endl;
    
//     // Season and day simulation

//     cout << "===========================================================================================================================================================================" << endl;

//     // DELETES
//     {
//         for (int i = 0; i < 8; i++)
//         {
//             delete first8Businesses[i];
//             first8Businesses[i] = nullptr;
//         }

//         delete[] first100;
//         first100 = nullptr;
//     }
    
// }

// void performDailyActivities()
// {
//     ((SocialAffairsDept *)(Gov->getDepartment("SocialAffairs")))->sendAdultsToWork();
//     ((FinanceDept *)(Government::getInstance()->getDepartment("Finance")))->getCRS()->settleTax();
// }

// void unleashDisease()
// {
//     cout << "THERE HAS BEEN AN OUTBREAK OF COS VIRUS" << endl;
//     for (int i = 0; i < 150; i++)
//     {
//        clinic->admitPatient(first100[i]);
//     }
    
// }

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

//     powerPlant = new PowerPlant("CityPower", static_cast<ResourceDepartment *>(ResourceDept), static_cast<Energy *>(EnergyResource), 20, apps[4]);
//     cout << endl; 
//     waterSupply = new WaterSupply("CityWater", static_cast<ResourceDepartment *>(ResourceDept), static_cast<Water *>(WaterResource), 20, apps[4]);
//     cout << endl; 
//     wasteManagement = new WasteManagement("CityWaste", static_cast<ResourceDepartment *>(ResourceDept), apps[4]);
//     cout << endl; 
//     SewerSystem = new SewageSystem("CitySewage", static_cast<ResourceDepartment *>(ResourceDept), apps[4]);
//     cout << endl; 

//     // ((ResourceDepartment *)ResourceDept)->addUtility(powerPlant);
//     // ((ResourceDepartment *)ResourceDept)->addUtility(waterSupply);
//     // ((ResourceDepartment *)ResourceDept)->addUtility(wasteManagement);
//     // ((ResourceDepartment *)ResourceDept)->addUtility(SewerSystem);
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

//     clinic->addSuccessor(GH);
//     clinic->addSuccessor(ICH);


//     for (int i = 0; i < 150; i++)
//     {
//         clinic->admitPatient(first100[i]);
//     }
// }

// void citizenObjects()
// {
//     AdultFactory = new AdultPop();
//     MinorFactory = new MinorPop();
// }

// void createBusinesses()
// {
//     first8Businesses[0] = new Automotive();
//     first8Businesses[1] = new Consulting();
//     first8Businesses[2] = new Entertainment();
//     first8Businesses[3] = new Food();
//     first8Businesses[4] = new Hospitality();
//     first8Businesses[5] = new Retail();
//     first8Businesses[6] = new Technology();
//     first8Businesses[7] = new Wellness();

//     first8Businesses[0]->linkWiseBucks(apps[3]);
//     first8Businesses[1]->linkWiseBucks(apps[2]);
//     first8Businesses[2]->linkWiseBucks(apps[2]);
//     first8Businesses[3]->linkWiseBucks(apps[1]);
//     first8Businesses[4]->linkWiseBucks(apps[1]);
//     first8Businesses[5]->linkWiseBucks(apps[5]);
//     first8Businesses[6]->linkWiseBucks(apps[1]);
//     first8Businesses[7]->linkWiseBucks(apps[2]);

//         for (Business *business : ((FinanceDept *)(Government::getInstance()->getDepartment("Finance")))->getBusinesses())
//         {
//             // NOT DESTRUCTED
//             business->buyProperty("Shop");
//         }

//         for (int i = 0; i < 8; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 first8Businesses[i]->hireEmployee();
//             }
//         }
// }

// void simulation()
// { 
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
//                     cout << "Autumn has arrived! " << endl << endl;
//                     currentSeason = "Spring";
//                 }
//                 cout << monthsOfTheYear[month] << "\n" << endl;
//                 autumn();
//                 cout << endl;
//             }
//             else if (month >= 6 && month <= 8)
//             {
//                 if (currentSeason != "Summer")
//                 {

//                     cout << "===========================================================================================================================================================================" << endl;
//                     cout << "Winter has arrived! " << endl << endl;
//                     currentSeason = "Summer";
//                 }
//                 cout << monthsOfTheYear[month] << "\n" << endl;
//                 winter();
//                 std::cout << endl;
//             }
//             else if (month >= 9 && month <= 11)
//             {
//                 if (currentSeason != "Autumn")
//                 {

//                     cout << "===========================================================================================================================================================================" << endl;
//                     cout << "Spring has arrived! " << endl << endl;
//                     currentSeason = "Autumn";
//                 }
//                 cout << monthsOfTheYear[month] << "\n" << endl;
//                 spring();
//                 std::cout << endl;
//             }
//             else
//             {
//                 if (currentSeason != "Winter")
//                 {

//                     cout << "===========================================================================================================================================================================" << endl;
//                     cout << "Summer has arrived!" << endl;
//                     if (monthsOfTheYear[month] == "December")
//                     {
//                         cout << "...Again!" << endl;
//                     }
//                     cout << endl;
//                     currentSeason = "Winter";
//                 }
//                 cout << monthsOfTheYear[month] << "\n" << endl;
//                 summer();
//                 cout << endl; 
//             }

//             cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
//             this_thread::sleep_for(chrono::milliseconds(5000));
//         }

// }

// void summer()
// {
//     cout << "Summer has arrived! " << endl << endl;

//     performDailyActivities();
// }

// void autumn()
// {
//     performDailyActivities();
// }

// void winter()
// {
//     performDailyActivities();
//     // unleashDisease();
// }

// void spring()
// {
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




///////////////////////////////////////
// #include <iostream>
// #include <vector>
// #include <string>

// // Include necessary headers for transport modes and facilities
// #include "TransportMode.h"
// #include "BusMode.h"
// #include "TrainMode.h"
// #include "TaxiMode.h"
// #include "CarMode.h"
// #include "AirplaneMode.h"
// #include "ModeFactory.h"
// #include "BusModeFactory.h"
// #include "BusStopFactory.h"
// #include "RoadFactory.h"
// #include "TrainModeFactory.h"
// #include "TaxiModeFactory.h"
// #include "TrainStationFactory.h"
// #include "RailwayFactory.h"
// #include "TaxiRankFactory.h"
// #include "AirplaneModeFactory.h"
// #include "AirportFactory.h"
// #include "CarModeFactory.h"

// #include "Department.h"
// #include "TransportDept.h"

// // Include observer and mediator headers
// #include "CitizenObserver.h"
// #include "ConcreteTransportationMediator.h"

// // Include state pattern headers
// #include "NormalState.h"
// #include "CongestedState.h"
// #include "EmptyState.h"

// // Include iterator headers
// #include "QueueIterator.h"
// #include "StackIterator.h"

// // Include facility headers
// #include "Road.h"
// #include "Railway.h"
// #include "Airport.h"

// // Function prototypes for setup, simulation, and cleanup
// void DemoMain();
// void simulation();
// void globalCleanUp();

// int main() {
//     // Initialize setup
//     DemoMain();

//     std::cout << "Starting the city simulation..." << std::endl;

//     // Seasonal simulation loop
//     simulation();

//     // Perform cleanup
//     globalCleanUp();

//     return 0;
// }

// void DemoMain() {
//     std::cout << "=== Factory Pattern ===" << std::endl;
    
//     // Setting up Transportation System
//     ModeFactory* busFactory = new BusModeFactory();
//     StationFactory* busStopFactory = new BusStopFactory();
//     FacilitiesFactory* roadFactory = new RoadFactory();
//     TransportDept* transportDept = new TransportDept(100000);

//     // Create other transport modes and facilities
//     ModeFactory* trainFactory = new TrainModeFactory();
//     StationFactory* trainStationFactory = new TrainStationFactory();
//     FacilitiesFactory* railwayFactory = new RailwayFactory();

//     ModeFactory* taxiFactory = new TaxiModeFactory();
//     StationFactory* taxiRankFactory = new TaxiRankFactory();

//     ModeFactory* airplaneFactory = new AirplaneModeFactory();
//     FacilitiesFactory* airportFactory = new AirportFactory();

//     ModeFactory* carFactory = new CarModeFactory();

//     ConcreteTransportationMediator* mediator = new ConcreteTransportationMediator();

//     // Create instances of each transport mode
//     TransportMode* bus1 = busFactory->createMode();
//     TransportMode* train1 = trainFactory->createMode();
//     TransportMode* taxi1 = taxiFactory->createMode();
//     TransportMode* airplane1 = airplaneFactory->createMode();
//     TransportMode* car1 = carFactory->createMode();

//     // Create instances of each station and facility
//     TransportStation* busStop1 = busStopFactory->createStation();
//     TransportStation* trainStation1 = trainStationFactory->createStation();
//     TransportStation* taxiRank1 = taxiRankFactory->createStation();

//     TransportFacilities* road1 = roadFactory->createFacilities();
//     TransportFacilities* railway1 = railwayFactory->createFacilities();
//     TransportFacilities* airport1 = airportFactory->createFacilities();

//     // Assign facilities to transport modes
//     bus1->SetFacilities(road1);
//     train1->SetFacilities(railway1);
//     taxi1->SetFacilities(railway1); // Adjust as per simulation design
//     airplane1->SetFacilities(airport1);
//     car1->SetFacilities(road1);

//     // Assign transport department to modes
//     bus1->SetTransDept(transportDept);
//     train1->SetTransDept(transportDept);
//     taxi1->SetTransDept(transportDept);
//     airplane1->SetTransDept(transportDept);
//     car1->SetTransDept(transportDept);

//     // Demonstration of functionality (Placeholder for further setup)
//     if (BusMode* bus = dynamic_cast<BusMode*>(bus1)) {
//         bus->SetMediator(mediator);
//         bus->addStop(busStop1);
//         bus->drive();
//     }
//     if (TrainMode* train = dynamic_cast<TrainMode*>(train1)) {
//         train->SetMediator(mediator);
//         train->addStop(trainStation1);
//         train->drive();
//     }

//     // Add facilities to department
//     transportDept->addFacility(road1);
//     transportDept->addFacility(railway1);
//     transportDept->addFacility(airport1);

//     // Clean up resources
//     delete bus1;
//     delete train1;
//     delete taxi1;
//     delete airplane1;
//     delete car1;
//     delete busStop1;
//     delete trainStation1;
//     delete taxiRank1;
//     delete road1;
//     delete railway1;
//     delete airport1;
//     delete mediator;
//     delete transportDept;
//     delete busFactory;
//     delete busStopFactory;
//     delete roadFactory;
//     delete trainFactory;
//     delete trainStationFactory;
//     delete railwayFactory;
//     delete taxiFactory;
//     delete taxiRankFactory;
//     delete airplaneFactory;
//     delete airportFactory;
//     delete carFactory;
// }

// void simulation() {
//     // Placeholder for simulation loop (can add seasonal events as needed)
//     std::cout << "Running simulation..." << std::endl;
// }

// void globalCleanUp() {
//     // Placeholder for cleaning up any remaining resources
//     std::cout << "Cleaning up resources..." << std::endl;
// }

