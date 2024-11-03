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
    BusMode busMode;
    TrainMode trainMode;
    TaxiMode taxiMode;
    CarMode carMode;
    AirplaneMode airplaneMode;

    std::cout << "Testing displayMode function:" << std::endl;
    busMode.displayMode();
    trainMode.displayMode();
    taxiMode.displayMode();
    carMode.displayMode();
    airplaneMode.displayMode();

    Road road;
    Railway railway;
    Airport airport;

    std::cout << "\n=== State Pattern ===" << std::endl;
    NormalState normalState;
    CongestedState congestedState;
    EmptyState emptyState;

    std::cout << "Testing state transitions for Road:" << std::endl;
    road.setState(&normalState);
    road.handleState();
    road.setState(&congestedState);
    road.handleState();
    road.setState(&emptyState);
    road.handleState();

    std::cout << "\nTesting state transitions for Railway:" << std::endl;
    railway.setState(&normalState);
    railway.handleState();
    railway.setState(&emptyState);
    railway.handleState();

    std::cout << "\nTesting state transitions for Airport:" << std::endl;
    airport.setState(&normalState);
    airport.handleState();
    airport.setState(&congestedState);
    airport.handleState();

    std::cout << "\n=== Observer Pattern ===" << std::endl;
    ConcreteTransportationMediator mediator;
    CitizenObserver observer1("Alice");
    CitizenObserver observer2("Bob");

    std::cout << "Adding observers and sending notifications:" << std::endl;
    mediator.addObserver(&observer1);
    mediator.addObserver(&observer2);
    mediator.notifyObservers("Traffic update: Road is congested");

    std::cout << "\n=== Iterator Pattern ===" << std::endl;
    std::vector<TransportMode*> transportModes = { &busMode, &trainMode, &taxiMode, &carMode, &airplaneMode };

    std::cout << "Testing QueueIterator:" << std::endl;
    QueueIterator queueIterator(transportModes);
    while(queueIterator.hasNext()) {
        TransportMode* mode = queueIterator.next();
        mode->displayMode();
    }

    std::cout << "\nTesting StackIterator:" << std::endl;
    StackIterator stackIterator(transportModes);
    while(stackIterator.hasNext()) {
        TransportMode* mode = stackIterator.next();
        mode->displayMode();
    }

    std::cout << "\n=== Mediator Pattern ===" << std::endl;
    mediator.addTransportMode(&busMode);
    mediator.addTransportMode(&trainMode);

    std::cout << "Testing coordination between BusMode and TrainMode:" << std::endl;
    mediator.coordinateTransport("BusMode", "TrainMode");

    std::cout << "\nAll functionality has been tested." << std::endl;
    return 0;
}