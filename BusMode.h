// BusMode.h

#pragma once
#include "TransportMode.h"
#include "Road.h"
#include "ModeFactory.h"
#include "BusIterator.h"
#include <list>
#include <memory>


class TransportFacilities;
class TransportationMediator;

class BusMode : public TransportMode {
private:
    Road* road;
    TransportFacilities* facility; //mediator
    std::list<TransportStation*> busStops; //iterator

public:
    BusMode();
    void operateStation() override;
    void useTransport() override;

    //Mediator
    BusMode(TransportationMediator* mediator, TransportFacilities* facility);

    std::string getName() const override;
    void alertAccident() override;
    void manageTraffic(const std::string& state) override;
    void set(const std::string& state) override;
    void changed(const std::string& state) override;

    TransportFacilities* getFacility() const override;
    bool isRoadMode() const override;
    bool isRailwayMode() const override;
    bool isAirportMode() const override;
    //Iterator
    // Method to add bus stops
    void addBusStop(TransportStation* stop);

    // Overridden method to create a BusIterator
    TransportationIterator* createIterator() override;
};