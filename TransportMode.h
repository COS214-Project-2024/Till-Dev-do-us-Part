// Abstract Products
// TransportMode.h
#include "TransState.h"
#include "TransportationMediator.h"
#include "TransportFacilities.h"
#include "TransportationIterator.h" 
#include "ConcreteTransportationMediator.h"
#include "TransportDept.h"
#pragma once
#include <list>
#include <vector>
#include <string>
#include <memory>

#include <algorithm>
#include <random>

class TransportationMediator;
class TransportFacilities;
class TransportIterator;
class CitizenObserver;
class TransportStation;
class ConcreteTransportationMediator;

class TransportMode {
protected:
    // std::string name;
    // double speed;
    // double capacity;
    ConcreteTransportationMediator* mediator;
    TransportFacilities* facility; //??????
    TransState* state;
    TransportIterator* iterator;
    std::list<TransportStation*> stops;

    // std::vector<CitizenObserver*> passengers;
    std::vector<TransportStation*> schedule;
    std::vector<CitizenObserver*> observers;  // List of observers (citizens)
    TransportDept* transDept;



public:
    TransportMode();
    // TransportMode(const std::string& name, double speed, double capacity); // Constructor

    virtual ~TransportMode()=default;

    void changeState(TransState newState);
    // void alertAccident();
    virtual void pickUpPassengers();
    virtual void dropOffPassengers();
    void notifySchedule();
    void registerCitizen(CitizenObserver* observer);
    void removeCitizen(CitizenObserver* observer);
    //TransState* getState();
    void setState(TransState newState);
    void setIterator(TransportIterator* newIterator);
    void AttachMediator(ConcreteTransportationMediator* newMediator);
    virtual void operateStation() = 0;
    virtual void useTransport() = 0;
    virtual void SendMessage(const std::string& state);
    virtual std::string GetMessage();
    virtual TransportFacilities* GetFacility();
    void divertingRoute();
    virtual void SetFacilities(TransportFacilities* facility);
    // virtual TransportMode* GetMode();
    
    

    //Mediator
    void changed(const std::string& state); // Notify mediator of changes
    virtual void travel() =0;
    virtual TransportFacilities* getFacility();
    // virtual TransportFacilities* getFacility() const = 0; // Returns the associated facility
    // const std::string& getName() const { return name; }
    // TransportMode(TransportationMediator* mediator) : mediator(mediator) {}

    virtual std::string getName() const = 0;
    virtual void alertAccident() = 0;
    virtual void manageTraffic(const std::string& state) = 0;
    virtual void set(const std::string& state) = 0;
    // virtual void changed(const std::string& state) = 0;

    // Iterator
    // Method to create an iterator for the mode's specific transport stations
    virtual TransportationIterator* createIterator();
    
    // Optional: method to add transport stations to the mode
    // virtual void addStation(TransportStation* station);

    // CitizenObserver
     // Methods to manage observers
    // void addObserver(CitizenObserver* observer);
    // void removeObserver(CitizenObserver* observer);
    // void notifyObservers(const std::string& message);

    // // Pure virtual functions for schedule management
    // virtual void setSchedule(const std::string& schedule) = 0;
    // virtual std::string getSchedule() const = 0;
    std::list<TransportStation*> getStops();


};