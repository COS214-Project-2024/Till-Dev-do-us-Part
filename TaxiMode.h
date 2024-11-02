// TaxiMode.h
#pragma once
#include "TransportMode.h"
#include "Road.h"
#include "TaxiRank.h"
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
    std::string state;
    TransportMode* mode;

public:
    TaxiMode();
    void drive();
    void stopDrive();

    //Mediator
    std::string getName() const override;
    void SendMessage(const std::string& state);
    std::string GetMessage();

    
    // Iterator??
    
    // CitizenObserver
    // void setSchedule(const std::string& newSchedule) override;
    // std::string getSchedule() const override;
    // void notifyScheduleChange();
    
};