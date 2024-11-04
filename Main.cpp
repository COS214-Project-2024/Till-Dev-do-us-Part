#include <iostream>
#include <vector>
#include <string>

// Include necessary headers for transport modes and facilities
#include "TransportMode.h"
#include "BusMode.h"
#include "TrainMode.h"
#include "TaxiMode.h"
#include "CarMode.h"
#include "AirplaneMode.h"
#include "ModeFactory.h"
#include "BusModeFactory.h"
#include "BusStopFactory.h"
#include "RoadFactory.h"
#include "TrainModeFactory.h"
#include "TaxiModeFactory.h"
#include "TrainStationFactory.h"
#include "RailwayFactory.h"
#include "TaxiRankFactory.h"
#include "AirplaneModeFactory.h"
#include "AirportFactory.h"
#include "CarModeFactory.h"

#include "Department.h"
#include "TransportDept.h"

// Include observer and mediator headers
#include "CitizenObserver.h"
#include "ConcreteTransportationMediator.h"

// Include state pattern headers
#include "NormalState.h"
#include "CongestedState.h"
#include "EmptyState.h"

// Include iterator headers
#include "QueueIterator.h"
#include "StackIterator.h"

// Include facility headers
#include "Road.h"
#include "Railway.h"
#include "Airport.h"

int main() {
    // Factory Pattern - Create instances of each transport mode and facility
    std::cout << "=== Factory Pattern ===" << std::endl;
    // Making bus
    ModeFactory* mainmee = new BusModeFactory();
    StationFactory* stst= new BusStopFactory();
    FacilitiesFactory* facil= new RoadFactory();
    TransportDept* ment= new TransportDept(100000);

    //Making Train
    ModeFactory* stat= new TrainModeFactory();
    StationFactory* gau= new TrainStationFactory();
    FacilitiesFactory* rail= new RailwayFactory();

    // Making taxi
    ModeFactory* tax = new TaxiModeFactory();
    StationFactory* rank= new TaxiRankFactory();

    // Making airplane
    ModeFactory* plane= new AirplaneModeFactory();
    FacilitiesFactory* port= new AirportFactory();

    // Car
    ModeFactory* car = new CarModeFactory();
    
    // Mediator
    ConcreteTransportationMediator* medi= new ConcreteTransportationMediator();

    // Buses
    TransportMode* momo = mainmee->createMode();
    TransportMode* nene = mainmee->createMode();
    TransportMode* a = mainmee->createMode();
    TransportMode* b = mainmee->createMode();
    TransportMode* c = mainmee->createMode();
    TransportMode* d = mainmee->createMode();
    TransportMode* e = mainmee->createMode();
    TransportMode* f = mainmee->createMode();
    TransportMode* g = mainmee->createMode();
    TransportMode* h = mainmee->createMode();
    TransportMode* i = mainmee->createMode();

    // Trains
    TransportMode* t = stat->createMode();
    TransportMode* r = stat->createMode();

    // Taxis
    TransportMode* x = tax->createMode();
    TransportMode* m = tax->createMode();

    // Airplanes
    TransportMode* n = plane->createMode();
    TransportMode* q = plane->createMode();

    // Car
    TransportMode* w = car ->createMode();
    TransportMode* y = car ->createMode();



    // Bus Stop
    TransportStation* opop= stst->createStation();
    TransportStation* p= stst->createStation();

    // Train Station 
    TransportStation* rosebank= gau->createStation();
    TransportStation* hatfield= gau->createStation();


    // Taxi Rank
    TransportStation* springs= rank->createStation();
    TransportStation* brakpan= rank->createStation();

    // Facilities 
    // Roads
    TransportFacilities* roro= facil->createFacilities();
    TransportFacilities* adad= facil->createFacilities();

    // Railways
    TransportFacilities* ai= rail->createFacilities();
    TransportFacilities* ay= rail->createFacilities();

    // Airport
    TransportFacilities* rp= port->createFacilities();
    TransportFacilities* rt= port->createFacilities();
  
    // add to dept
    ment->addFacility(roro);
    ment->addFacility(adad);
    ment->addFacility(ai);
    ment->addFacility(ay);
    ment->addFacility(rp);
    ment->addFacility(rt);


    // set facil
    // Buses
    momo->SetFacilities(roro);
    nene->SetFacilities(roro);
    a->SetFacilities(roro);
    b->SetFacilities(roro);
    c->SetFacilities(roro);
    d->SetFacilities(roro);
    e->SetFacilities(roro);
    f->SetFacilities(roro);
    g->SetFacilities(roro);
    h->SetFacilities(roro);
    i->SetFacilities(roro);

    // Trains
    t->SetFacilities(ai);
    r->SetFacilities(ai);

    // Taxi
    x->SetFacilities(ai);
    m->SetFacilities(ai);

    // Planes
    n->SetFacilities(rp);
    q->SetFacilities(rt);

    // Cars
    w->SetFacilities(roro);
    y->SetFacilities(roro);

    // set dept
    // Buses
    momo->SetTransDept(ment);
    nene->SetTransDept(ment);
    a->SetTransDept(ment);
    b->SetTransDept(ment);
    c->SetTransDept(ment);
    d->SetTransDept(ment);
    e->SetTransDept(ment);
    f->SetTransDept(ment);
    g->SetTransDept(ment);
    h->SetTransDept(ment);
    i->SetTransDept(ment);

    // Trains
    t->SetTransDept(ment);
    r->SetTransDept(ment);

    // Taxis
    x->SetTransDept(ment);
    m->SetTransDept(ment);

    // Planes
    n->SetTransDept(ment);
    q->SetTransDept(ment);



    
    if (momo == nullptr) {
    std::cerr << "momo is nullptr!" << std::endl;
    } 
    else {
    std::cout << "Transport Mode Name: " << momo->getName() << std::endl;

    // Attempt to downcast to BusMode to call drive()
    if (TransportMode* bus = dynamic_cast<BusMode*>(momo)) {
        bus->SetMediator(medi);
        bus->SetFacilities(roro);
        bus->addStop(opop);
        bus->addStop(p);
        nene->SetMediator(medi);

        
        ((BusMode*)bus)->drive(); // Call drive() if momo is indeed a BusMode
    } else {
        std::cerr << "Error: momo is not a BusMode instance." << std::endl;
    }

    if (TransportMode* tray = dynamic_cast<TrainMode*>(t)) {
        tray->SetMediator(medi);
        tray->SetFacilities(ai);
        tray->addStop(rosebank);
        tray->addStop(hatfield);
        r->SetMediator(medi);

        
        ((TrainMode*)tray)->drive(); // Call drive() if momo is indeed a BusMode
    } else {
        std::cerr << "Error: momo is not a BusMode instance." << std::endl;
    }

     if (TransportMode* axi = dynamic_cast<TaxiMode*>(x)) {
        axi->SetMediator(medi);
        axi->SetFacilities(rp);
        axi->addStop(springs);
        axi->addStop(brakpan);
        m->SetMediator(medi);

        
        ((TrainMode*)axi)->drive(); // Call drive() if momo is indeed a BusMode
    } else {
        // std::cerr << "Error: taxi is not a BusMode instance." << std::endl;
    }

    if (TransportMode* play = dynamic_cast<AirplaneMode*>(n)) {
        play->SetMediator(medi);
        play->SetFacilities(rp);
        // play->addStop(springs);
        // play->addStop(brakpan);
        q->SetMediator(medi);

        
        ((TrainMode*)play)->drive(); // Call drive() if momo is indeed a BusMode
    } else {
        // std::cerr << "Error: plane is not a BusMode instance." << std::endl;
    }

    if (TransportMode* cr = dynamic_cast<CarMode*>(w)) {
        cr->SetMediator(medi);
        cr->SetFacilities(roro);
        // play->addStop(springs);
        // play->addStop(brakpan);
        y->SetMediator(medi);

        
        ((TrainMode*)cr)->drive(); // Call drive() if momo is indeed a BusMode
    } else {
        // std::cerr << "Error: car is not a BusMode instance." << std::endl;
    }
}

// Buses
delete momo;
delete nene;
delete a;
delete b;
delete c;
delete d;
delete e;
delete f;
delete g;
delete h;
delete i;

// Trains
delete t;
delete r;

// Taxi 
delete x;
delete m;

// Airplanes
delete n;
delete q;

// cars
delete w;
delete y;

// Stops
delete opop;
delete p;
delete rosebank;
delete hatfield;
delete springs;
delete brakpan;

//  Facilities already deleted 
// delete roro;
// delete adad;

// Rest
// Bus
delete medi;
delete ment;
delete facil;
delete stst;
delete mainmee;

// Train
delete rail;
delete gau;
delete stat;

// Taxi
delete rank;
delete tax;

// Airplane
delete port;
delete plane;

// Car
delete car;


    return 0;
}





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

//     // displayIntro();

//     cout << "===========================================================================================================================================================================" << endl;

//     cout << "Appearance of the first 150 citizens" << endl;

//     cout << "===========================================================================================================================================================================" << endl;
    
//     cout << "Creating Goverment and its Departments:" << endl;
//     governmentObjects();

//     citizenObjects();
//     Citizen **first100 = AdultFactory->reproduce(150);
//     {
//         for (int i = 0; i < 100; i++)
//         {
//             ((Adult *)first100[i])->setHouse(((DevelopmentDept *)(Gov->getDepartment("Development")))->build("House"));
//             ((SocialAffairsDept *)(Gov->getDepartment("SocialAffairs")))->addCitizen(first100[i]);
//             ((SocialAffairsDept *)(Gov->getDepartment("SocialAffairs")))->addToUnemployed(first100[i]);
//         }
//     }

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

//     cout << "Creating businesses to get the economy going..." << endl;
//     createBusinesses(); 

//     cout << "===========================================================================================================================================================================" << endl;
    
//     // Season and day simulation
//     simulation(); 

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

//     ((ResourceDepartment *)ResourceDept)->addUtility(powerPlant);
//     ((ResourceDepartment *)ResourceDept)->addUtility(waterSupply);
//     ((ResourceDepartment *)ResourceDept)->addUtility(wasteManagement);
//     ((ResourceDepartment *)ResourceDept)->addUtility(SewerSystem);
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
//                     autumn();
//                     cout << endl;
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
//                     cout << "Summer has arrived!" << endl;
//                     if (monthsOfTheYear[month] == "December")
//                     {
//                         cout << "...Again!";
//                     }
//                     cout << endl;
//                     summer();
//                     currentSeason = "Winter";
//                 }
//             }

//             cout << monthsOfTheYear[month] << "\n";
//             cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
//             this_thread::sleep_for(chrono::milliseconds(5000));
//         }

// }

// void summer()
// {
//     performDailyActivities();
//     // for (int i = 0; i < 10; i++)
//     // {
//     //     performDailyActivities();
//     // }
// }

// void autumn()
// {
//     cout << "Autumn has arrived! " << endl << endl;
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

