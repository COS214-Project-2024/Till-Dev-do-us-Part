// Abstract Products
// TransportMode.h
#ifndef TRANSPORTMODE_H
#define TRANSPORTMODE_H

#include "TransState.h"
#include "TransportationMediator.h"
#include "TransportFacilities.h"
#include "TransportationIterator.h" 
#include "TransportStation.h"
#include "ConcreteTransportationMediator.h"
#include "TransportDept.h"
#include "QueueIterator.h"
#include "StackIterator.h"
#include "CitizenObserver.h"
#include "TransportDept.h"
#pragma once
#include <list>
#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include <algorithm>
#include <random>
class TransportFacilities;
class ConcreteTransportationMediator;
class TransportDept;

class TransportMode {
protected:
    ConcreteTransportationMediator* mediator;
    TransportFacilities* facility; //??????
    std::string state;
    std::list<TransportStation*> stops;
    // std::vector<TransportStation*> schedule;
    std::vector<CitizenObserver*> observers;  // List of observers (citizens)
    TransportDept* transDept;

public:
    //TransportMode();
    // TransportMode(const std::string& name, double speed, double capacity); // Constructor
    void changed(std::string state);
    virtual ~TransportMode();
    void travel();
    
    virtual void SendMessage(std::string state)=0;
    virtual std::string GetMessage()=0;
    virtual TransportFacilities* GetFacility();
    void divertingRoute(std::string type);
    virtual void SetFacilities(TransportFacilities* facility);
    virtual void SetTransDept(TransportDept* transDept)=0;
    virtual void drive()=0;
    virtual void stopdrive()=0;


    //Mediator
    virtual std::string getName() const = 0;
    void SetMediator(ConcreteTransportationMediator* mediator);

    virtual TransportationIterator* createQIterator();
    virtual TransportationIterator* createSIterator();

    std::list<TransportStation*> getStops();
    void addStop(TransportStation* stop);


};
#endif