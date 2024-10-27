// ConcreteTransportFactory.cpp
#include "ConcreteTransportFactory.h"
#include "CarMode.h"
#include "BusMode.h"
#include "TrainMode.h"
#include "AirplaneMode.h"
#include "BusStop.h"
#include "TrainStation.h"
#include "Airport.h"

TransportMode* ConcreteTransportFactory::createMode(const std::string& type) {
    if (type == "car") return new CarMode();
    if (type == "bus") return new BusMode();
    if (type == "train") return new TrainMode();
    if (type == "airplane") return new AirplaneMode();
    return nullptr;
}

TransportStation* ConcreteTransportFactory::createStation(const std::string& type) {
    if (type == "bus") return new BusStop();
    if (type == "train") return new TrainStation();
    if (type == "airport") return new Airport();
    return nullptr;
}

TransportFacilities* ConcreteTransportFactory::createTransFacilities(const std::string& type) {
    if (type == "road") return new Road();
    if (type == "railway") return new Railway();
    if (type == "airport") return new Airport();
    return nullptr;
}