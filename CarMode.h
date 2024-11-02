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
public:
    CarMode();
    void drive();
    void stopDrive();
    
    //Mediator
    void SendMessage(const std::string& state);
    std::string GetMessage();
    std::string getName() const override;
    
};