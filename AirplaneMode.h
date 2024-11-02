// AirplaneMode.h
#pragma once
#include "TransportMode.h"
#include "TransportFacilities.h"
#include "Airport.h"
#include "TransState.h"
#include "ModeFactory.h"
#include "ConcreteTransportationMediator.h"
#include <algorithm>


class TransportFacilities;
class TransportationMediator;
class ConcreteTransportationMediator;

class AirplaneMode: public TransportMode {
private:
    Airport* airport;
    TransportFacilities* facility;
    std::string state;
    TransportMode* mode;
    

public:
    AirplaneMode();
    void depart();
    void arrive();

    //Mediator
    void SendMessage(const std::string& state);
    std::string GetMessage();
    std::string getName() const override;

    // Iterator???

    // CitizenObserver
    // void setSchedule(const std::string& newSchedule) override;
    // std::string getSchedule() const override;
    // void notifyScheduleChange();
    
};
