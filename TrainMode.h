// TrainMode.h
#pragma once
#include "TransportMode.h"
#include "Railway.h"
#include <string>
#include <iostream>

class TransportFacilities;
class TransportationMediator;

class TrainMode : public TransportMode {
private:
    Railway* railway;
    TransportFacilities* facility;
    std::string schedule; //observer



public:
    TrainMode();
    TrainMode(Railway* railway, const std::string& name, double speed, double capacity);
    void operateStation() override;
    void useTransport() override;
     ~TrainMode(); // Destructor to handle removal from railway

    //Mediator 
    TrainMode(TransportationMediator* mediator, TransportFacilities* facility);

    std::string getName() const override;
    void alertAccident() override;
    void manageTraffic(const std::string& state) override;
    void set(const std::string& state) override;
    void changed(const std::string& state) override;

    TransportFacilities* getFacility() const override;
    bool isRoadMode() const override;
    bool isRailwayMode() const override;
    bool isAirportMode() const override;

    //CitizenObserver
    void setSchedule(const std::string& newSchedule) override;
    std::string getSchedule() const override;
    void notifyScheduleChange();
};
