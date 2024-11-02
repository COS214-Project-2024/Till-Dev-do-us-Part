// Abstract Products
// TransportMode.h
#include "TransState.h"
#include "TransportationMediator.h"
#include "TransportFacilities.h"
#include "TransportationIterator.h" 
#include "ConcreteTransportationMediator.h"
#include "TransportDept.h"
#include "QueueIterator.h"
#include "StackIterator.h"
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
    ConcreteTransportationMediator* mediator;
    TransportFacilities* facility; //??????
    std::string state;
    std::list<TransportStation*> stops;
    std::vector<TransportStation*> schedule;
    std::vector<CitizenObserver*> observers;  // List of observers (citizens)
    TransportDept* transDept;

public:
    //TransportMode();
    // TransportMode(const std::string& name, double speed, double capacity); // Constructor
    void changed(const std::string& state);
    virtual ~TransportMode()=default;
    void TransportMode::travel();

    virtual void operateStation() = 0;
    virtual void useTransport() = 0;
    virtual void SendMessage(const std::string& state)=0;
    virtual std::string GetMessage()=0;
    virtual TransportFacilities* GetFacility();
    void divertingRoute();
    virtual void SetFacilities(TransportFacilities* facility);

    //Mediator
    virtual std::string getName() const = 0;
    void SetMediator(ConcreteTransportationMediator* mediator);

    virtual TransportationIterator* createQIterator();
    virtual TransportationIterator* createSIterator();

    std::list<TransportStation*> getStops();
    void addStop(TransportStation* stop);


};