// TaxiMode.h
#pragma once
#include "TransportMode.h"
#include "Road.h"
#include "TaxiRankIterator.h"
#include <list>
#include <vector>
#include <memory>
#include <string>
#include <iostream>

class TransportFacilities;
class TransportationMediator;
class TransportStation;

class TaxiMode : public TransportMode {
private:
    Road* road;
    TransportFacilities* facility;
    std::list<TransportStation*> taxiRanks;//iterator
    std::string schedule;//observer


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

    // Road addVehicle(TransportMode* vehicle);

    // Iterator??
    void addTaxiRank(TransportStation* rank);

    TransportationIterator* createIterator() override;

    // CitizenObserver
    void setSchedule(const std::string& newSchedule) override;
    std::string getSchedule() const override;
    void notifyScheduleChange();
    
};