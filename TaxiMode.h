// TaxiMode.h
#pragma once
#include "TransportMode.h"
#include "Road.h"
#include <string>
#include <list>
#include <iostream>

class TransportFacilities;
class TransportationMediator;

class TaxiMode : public TransportMode {
private:
    Road* road;
    TransportFacilities* facility;

public:
    TaxiMode();
    void operateStation() override;
    void useTransport() override;

    //Mediator
    TaxiMode(TransportationMediator* mediator, TransportFacilities* facility);

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