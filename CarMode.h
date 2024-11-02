// CarMode.h
#pragma once
#include "TransportMode.h"
#include "Road.h"
#include "ModeFactory.h"
#include "TransportFacilities.h"
#include "TransState.h"
#include "ModeFactory.h"
#include "ConcreteTransportationMediator.h"
#include <algorithm>


class TransportFacilities;
class TransportationMediator;
class ConcreteTransportationMediator;

class CarMode : public TransportMode {
private:
    Road* road;
    TransportFacilities* facility;
    std::string schedule;
    std::string state;
    TransportMode* mode;

public:
    CarMode();
    void drive();
    void stopDrive();
    
    //Mediator
    void SendMessage(const std::string& state);
    std::string GetMessage();
    std::string getName() const override;
    
    //Iterator???

    // //CitizenObserver
    // void setSchedule(const std::string& newSchedule) override;
    // std::string getSchedule() const override;
    // void notifyScheduleChange();
    
};