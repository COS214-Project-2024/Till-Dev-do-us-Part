// CarMode.h
#pragma once
#include "TransportMode.h"
#include "Road.h"
#include "ModeFactory.h"


class TransportFacilities;
class TransportationMediator;

class CarMode : public TransportMode {
private:
    Road* road;
    TransportFacilities* facility;

public:
    CarMode();
    void operateStation() override;
    void useTransport() override;

    //Mediator
    CarMode(TransportationMediator* mediator, TransportFacilities* facility);

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