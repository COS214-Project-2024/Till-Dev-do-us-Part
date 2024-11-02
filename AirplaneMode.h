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
    // std::string schedule; //observer

public:
    AirplaneMode();
    void depart();
    void arrive();
    void SetFacilities(Airport* airport);

    //Mediator
    // AirplaneMode(TransportationMediator* mediator, TransportFacilities* facility);
    void SendMessage(const std::string& state);
    std::string GetMessage();
    std::string getName() const override;
    void changed(const std::string& state) override;
    void travel() override;
    TransportFacilities* GetFacility();

    // Iterator???

    // CitizenObserver
    void setSchedule(const std::string& newSchedule) override;
    std::string getSchedule() const override;
    void notifyScheduleChange();
    
};
