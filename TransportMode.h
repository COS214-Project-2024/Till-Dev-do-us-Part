// Abstract Products
// TransportMode.h
#include "TransState.h"
#pragma once
#include <vector>
#include <string>
#include <memory>

class TransportationMediator;
class TransportIterator;
class CitizenObserver;
class TransportStation;

enum class TransState {
    NORMAL,
    CONGESTED,
    EMPTY
};

class TransportMode {
protected:
    std::string name;
    double speed;
    double capacity;
    TransportationMediator* mediator;
    TransState* state;
    TransportIterator* iterator;
    std::vector<CitizenObserver*> passengers;
    std::vector<TransportStation*> schedule;

public:
    TransportMode();
    TransportMode(const std::string& name, double speed, double capacity); // Constructor

    virtual ~TransportMode();

    void changeState(TransState newState);
    void alertAccident();
    virtual void pickUpPassengers();
    virtual void dropOffPassengers();
    void notifySchedule();
    void registerCitizen(CitizenObserver* observer);
    void removeCitizen(CitizenObserver* observer);
    TransState getState() const;
    void setState(TransState newState);
    void setIterator(TransportIterator* newIterator);
    void setMediator(TransportationMediator* newMediator);
    virtual void operateStation() = 0;
    virtual void useTransport() = 0;
};