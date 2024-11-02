// BusMode.h

#pragma once
#include "TransportMode.h"
#include "Road.h"
#include "ModeFactory.h"
#include "BusIterator.h"
#include "CitizenObserver.h"
#include "QueueIterator.h"
#include "StackIterator.h"
#include <vector>
#include <string>
#include <list>
#include <memory>


class TransportFacilities;
class TransportationMediator;

class BusMode : public TransportMode {
private:
    Road* road;
    TransportFacilities* facility; //mediator
    std::list<TransportStation*> busStops; //iterator
    std::string schedule; //observer


public:
    BusMode();
    void operateStation() override;
    void useTransport() override;
    void drive();
    void stopDrive();

    //Mediator
    // BusMode(TransportationMediator* mediator, TransportFacilities* facility);
    void SetMediator(TransportationMediator* mediator);
    void SetRoad(Road* road);
    TransportFacilities* GetFacility();



    std::string getName() const override;
    void alertAccident() override;
    void manageTraffic(const std::string& state) override;
    void set(const std::string& state) override;
    void changed(const std::string& state) override;

    // TransportFacilities* getFacility() const override;
    bool isRoadMode() const override;
    bool isRailwayMode() const override;
    bool isAirportMode() const override;

    //Iterator
    // Method to add bus stops
    void addBusStop(TransportStation* stop);

    // Overridden method to create a BusIterator
    TransportationIterator* createIterator() override;

    // CitizenObserver
    void setSchedule(const std::string& newSchedule) override;
    std::string getSchedule() const override;
    void notifyScheduleChange();

};