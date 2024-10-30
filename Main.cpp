#include <iostream>
#include <memory>
#include "TransportMode.h"
#include "BusMode.h"
#include "TrainMode.h"
#include "TaxiMode.h"
#include "CarMode.h"
#include "AirplaneMode.h"
#include "CitizenObserver.h"
#include "Adult.h"
#include "Minor.h"
#include "TransState.h"
#include "NormalState.h"
#include "CongestedState.h"
#include "EmptyState.h"
#include "TransportationMediator.h"
#include "ConcreteTransportationMediator.h"
#include "BusIterator.h"
#include "TrainStationIterator.h"
#include "TaxiRankIterator.h"
#include "Road.h"
#include "Railway.h"
#include "Airport.h"

int main() {
    // Testing Factory Method by Creating Different Transport Modes and Facilities
    std::cout << "Factory Method Pattern - Creating Transport Modes and Facilities\n";
    BusMode busMode;
    TrainMode trainMode;
    TaxiMode taxiMode;
    CarMode carMode;
    AirplaneMode airplaneMode;
    
    Road road;
    Railway railway;
    Airport airport;

    // // Testing State Pattern - Setting and Changing State of Facilities
    // std::cout << "\nState Pattern - Changing Facility States\n";
    // NormalState normalState;
    // CongestedState congestedState;
    // EmptyState emptyState;

    // road.setState(&normalState);
    // road.handleState();
    // road.setState(&congestedState);
    // road.handleState();
    // road.setState(&emptyState);
    // road.handleState();

    // railway.setState(&normalState);
    // railway.handleState();
    // airport.setState(&congestedState);
    // airport.handleState();

    // // Testing Observer Pattern - Citizens Subscribe to Transport Schedules
    // std::cout << "\nObserver Pattern - Citizens Subscribing to Schedules\n";
    // Adult adult1("John Doe");
    // Minor minor1("Jane Smith");

    // busMode.addObserver(&adult1);
    // busMode.addObserver(&minor1);
    // trainMode.addObserver(&minor1);  // Minor subscribing to train schedule

    // busMode.setSchedule("Buses depart every 15 minutes.");
    // trainMode.setSchedule("Trains depart every 30 minutes.");

    // busMode.setSchedule("Bus delay: traffic congestion.");
    // trainMode.setSchedule("Train delay: maintenance on tracks.");

    // // Testing Mediator Pattern - Communication between Modes on Road, Railway, and Airport
    // std::cout << "\nMediator Pattern - Inter-Mode Communication\n";
    // ConcreteTransportationMediator mediator;
    // busMode.setMediator(&mediator);
    // taxiMode.setMediator(&mediator);
    // trainMode.setMediator(&mediator);
    // airplaneMode.setMediator(&mediator);

    // mediator.registerMode(&busMode);
    // mediator.registerMode(&taxiMode);
    // mediator.registerMode(&trainMode);
    // mediator.registerMode(&airplaneMode);

    // busMode.alertAccident();
    // trainMode.alertAccident();
    // airplaneMode.alertAccident();

    // // Testing Iterator Pattern - Iterating through Transport Stations
    // std::cout << "\nIterator Pattern - Route Navigation\n";
    // BusIterator busIterator(busMode.getBusStops());
    // TrainStationIterator trainIterator(trainMode.getTrainStations());
    // TaxiRankIterator taxiIterator(taxiMode.getTaxiRanks());
    // AirportIterator airportIterator(airplaneMode.getAirports());

    // std::cout << "Bus Route:\n";
    // while (busIterator.hasNext()) {
    //     TransportStation* station = busIterator.next();
    //     station->handlePassengers();
    // }

    // std::cout << "\nTrain Route:\n";
    // while (trainIterator.hasNext()) {
    //     TransportStation* station = trainIterator.next();
    //     station->handlePassengers();
    // }

    // std::cout << "\nTaxi Route:\n";
    // while (taxiIterator.hasNext()) {
    //     TransportStation* station = taxiIterator.next();
    //     station->handlePassengers();
    // }

    // std::cout << "\nAirport Itinerary:\n";
    // while (airportIterator.hasNext()) {
    //     TransportStation* station = airportIterator.next();
    //     station->handlePassengers();
    // }

    // // Testing Specific Functions for Each Transport Mode
    // std::cout << "\nTesting Transport Mode Specific Functions\n";
    // std::cout << "Bus Mode Schedule: " << busMode.getSchedule() << "\n";
    // std::cout << "Train Mode Schedule: " << trainMode.getSchedule() << "\n";
    // std::cout << "Taxi Mode Schedule: " << taxiMode.getSchedule() << "\n";
    // std::cout << "Car Mode Schedule: " << carMode.getSchedule() << "\n";
    // std::cout << "Airplane Mode Schedule: " << airplaneMode.getSchedule() << "\n";

    // // Cleanup and Verification of Proper Destruction
    // std::cout << "\nCleaning up and finalizing the test...\n";

    return 0;
}
