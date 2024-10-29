// Abstract Products
// TransportMode.h
#include "TransState.h"
#include "TransportationMediator.h"
#include "TransportFacilities.h"
#pragma once
#include <vector>
#include <string>
#include <memory>

class TransportationMediator;
class TransportFacilities;
class TransportIterator;
class CitizenObserver;
class TransportStation;

class TransportMode {
protected:
    std::string name;
    double speed;
    double capacity;
    TransportationMediator* mediator;
    TransportFacilities* facility;
    TransState* state;
    TransportIterator* iterator;
    std::vector<CitizenObserver*> passengers;
    std::vector<TransportStation*> schedule;

public:
    TransportMode();
    TransportMode(const std::string& name, double speed, double capacity); // Constructor

    virtual ~TransportMode()=default;

    void changeState(TransState newState);
    // void alertAccident();
    virtual void pickUpPassengers();
    virtual void dropOffPassengers();
    void notifySchedule();
    void registerCitizen(CitizenObserver* observer);
    void removeCitizen(CitizenObserver* observer);
    TransState getState();
    void setState(TransState newState);
    void setIterator(TransportIterator* newIterator);
    void setMediator(TransportationMediator* newMediator);
    virtual void operateStation() = 0;
    virtual void useTransport() = 0;

    //Mediator
    virtual void changed(const std::string& state) = 0; // Notify mediator of changes
    virtual bool isRoadMode() const = 0;
    virtual bool isRailwayMode() const = 0;
    virtual bool isAirportMode() const = 0;
    virtual TransportFacilities* getFacility() const = 0; // Returns the associated facility
    // const std::string& getName() const { return name; }
    TransportMode(TransportationMediator* mediator) : mediator(mediator) {}

    virtual std::string getName() const = 0;
    virtual void alertAccident() = 0;
    virtual void manageTraffic(const std::string& state) = 0;
    virtual void set(const std::string& state) = 0;
    // virtual void changed(const std::string& state) = 0;

};