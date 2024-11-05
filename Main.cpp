#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest/doctest.h"

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
#include "CitizenObserver.h"
#include "ConcreteTransportationMediator.h"
#include "NormalState.h"
#include "CongestedState.h"
#include "EmptyState.h"
#include "QueueIterator.h"
#include "StackIterator.h"
#include "Road.h"
#include "Railway.h"
#include "Airport.h"

TEST_CASE("Transport System Factory Creation") {
    // Create factories
    ModeFactory* busFactory = new BusModeFactory();
    StationFactory* busStopFactory = new BusStopFactory();
    FacilitiesFactory* roadFactory = new RoadFactory();
    TransportDept* transportDept = new TransportDept(100000);
    
    SUBCASE("Bus Mode Creation") {
        TransportMode* bus = busFactory->createMode();
        CHECK(bus != nullptr);
        CHECK(dynamic_cast<BusMode*>(bus) != nullptr);
        delete bus;
    }
    
    SUBCASE("Bus Stop Creation") {
        TransportStation* busStop = busStopFactory->createStation();
        CHECK(busStop != nullptr);
        delete busStop;
    }
    
    SUBCASE("Road Creation") {
        TransportFacilities* road = roadFactory->createFacilities();
        CHECK(road != nullptr);
   
    }
    
    // Cleanup
    delete busFactory;
    delete busStopFactory;
    delete roadFactory;
    delete transportDept;
}

TEST_CASE("Train System Creation") {
    ModeFactory* trainFactory = new TrainModeFactory();
    StationFactory* trainStationFactory = new TrainStationFactory();
    FacilitiesFactory* railwayFactory = new RailwayFactory();
    
    SUBCASE("Train Mode Creation") {
        TransportMode* train = trainFactory->createMode();
        CHECK(train != nullptr);
        CHECK(dynamic_cast<TrainMode*>(train) != nullptr);
        delete train;
    }
    
    SUBCASE("Train Station Creation") {
        TransportStation* trainStation = trainStationFactory->createStation();
        CHECK(trainStation != nullptr);
        delete trainStation;
    }
    
    SUBCASE("Railway Creation") {
        TransportFacilities* railway = railwayFactory->createFacilities();
        CHECK(railway != nullptr);
   
    }
    
    // Cleanup
    delete trainFactory;
    delete trainStationFactory;
    delete railwayFactory;
}

TEST_CASE("Transport Mode Integration") {
    ModeFactory* busFactory = new BusModeFactory();
    StationFactory* busStopFactory = new BusStopFactory();
    FacilitiesFactory* roadFactory = new RoadFactory();
    TransportDept* transportDept = new TransportDept(100000);
    ConcreteTransportationMediator* mediator = new ConcreteTransportationMediator();
    
    SUBCASE("Bus Integration") {
        TransportMode* bus = busFactory->createMode();
        TransportFacilities* road = roadFactory->createFacilities();
        TransportStation* busStop1 = busStopFactory->createStation();
        TransportStation* busStop2 = busStopFactory->createStation();
        
        CHECK_NOTHROW(bus->SetMediator(mediator));
        CHECK_NOTHROW(bus->SetFacilities(road));
        CHECK_NOTHROW(bus->SetTransDept(transportDept));
        CHECK_NOTHROW(bus->addStop(busStop1));
        CHECK_NOTHROW(bus->addStop(busStop2));
        
        if (BusMode* busMode = dynamic_cast<BusMode*>(bus)) {
            CHECK_NOTHROW(busMode->drive());
        }
        
    
    }
    
    // Cleanup
    delete busFactory;
    delete busStopFactory;
    delete roadFactory;
    delete transportDept;
    delete mediator;
}

TEST_CASE("Transport Department Management") {
    TransportDept* transportDept = new TransportDept(100000);
    FacilitiesFactory* roadFactory = new RoadFactory();
    FacilitiesFactory* railFactory = new RailwayFactory();
    
    SUBCASE("Facility Management") {
        TransportFacilities* road = roadFactory->createFacilities();
        TransportFacilities* railway = railFactory->createFacilities();
        
        CHECK_NOTHROW(transportDept->addFacility(road));
        CHECK_NOTHROW(transportDept->addFacility(railway));
        

     }
    
//     // Cleanup
     delete transportDept;

 }

TEST_CASE("Multiple Transport Modes Integration") {
    TransportDept* transportDept = new TransportDept(100000);
    ConcreteTransportationMediator* mediator = new ConcreteTransportationMediator();
    
    // Create factories
    ModeFactory* busFactory = new BusModeFactory();
    ModeFactory* trainFactory = new TrainModeFactory();
    ModeFactory* taxiFactory = new TaxiModeFactory();
    
    SUBCASE("Multi-mode Operation") {
        TransportMode* bus = busFactory->createMode();
        TransportMode* train = trainFactory->createMode();
        TransportMode* taxi = taxiFactory->createMode();
        
        CHECK_NOTHROW(bus->SetMediator(mediator));
        CHECK_NOTHROW(train->SetMediator(mediator));
        CHECK_NOTHROW(taxi->SetMediator(mediator));
        
        CHECK_NOTHROW(bus->SetTransDept(transportDept));
        CHECK_NOTHROW(train->SetTransDept(transportDept));
        CHECK_NOTHROW(taxi->SetTransDept(transportDept));
        
        delete bus;
        delete train;
        delete taxi;
    }
    
    // Cleanup
    delete transportDept;
    delete mediator;
    delete busFactory;
    delete trainFactory;
    delete taxiFactory;
}