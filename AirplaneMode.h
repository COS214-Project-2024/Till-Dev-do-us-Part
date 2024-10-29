// AirplaneMode.h
#pragma once
#include "TransportMode.h"
#include "TransportFacilities.h"
#include "Airport.h"
#include "TransState.h"
#include "ModeFactory.h"

class TransportFacilities;
class TransportationMediator;

class AirplaneMode : public TransportMode {
private:
    Airport* airport;
    TransportFacilities* facility;

public:
    AirplaneMode();
    void operateStation() override;
    void useTransport() override;

    //Mediator
    AirplaneMode(TransportationMediator* mediator, TransportFacilities* facility);

    std::string getName() const override;
    void alertAccident() override;
    void manageTraffic(const std::string& state) override;
    void set(const std::string& state) override;
    void changed(const std::string& state) override;

    TransportFacilities* getFacility() const override;
    bool isRoadMode() const override;
    bool isRailwayMode() const override;
    bool isAirportMode() const override;
    
};

// // Airport.h
// #pragma once
// #include "TransportStation.h"
// #include <vector>

// class Airport : public TransportStation, public TransportFacilities {
// private:
//     int planesCount;
//     std::vector<TransportMode*> planes;

// public:
//     void handlePassengers() override;
//     void manageFreight() override;
//     void maintain() override;
//     void useTransport() override;
//     void addPlane(TransportMode* plane);
//     void removePlane(TransportMode* plane);
// };