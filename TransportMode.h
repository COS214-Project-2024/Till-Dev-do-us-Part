// Abstract Products
// TransportMode.h
#include "TransState.h"
#include "TransportationMediator.h"
#include "TransportFacilities.h"
#include "TransportationIterator.h" 
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
    // std::vector<CitizenObserver*> passengers;
    std::vector<TransportStation*> schedule;
    std::vector<CitizenObserver*> observers;  // List of observers (citizens)


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

    // Iterator
    // Method to create an iterator for the mode's specific transport stations
    virtual TransportationIterator* createIterator() = 0;
    
    // Optional: method to add transport stations to the mode
    virtual void addStation(TransportStation* station) = 0;

    // CitizenObserver
     // Methods to manage observers
    void addObserver(CitizenObserver* observer);
    void removeObserver(CitizenObserver* observer);
    void notifyObservers(const std::string& message);

    // Pure virtual functions for schedule management
    virtual void setSchedule(const std::string& schedule) = 0;
    virtual std::string getSchedule() const = 0;
};