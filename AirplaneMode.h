// AirplaneMode.h
#pragma once
#include "TransportMode.h"
#include "TransportFacilities.h"
#include "Airport.h"
#include "TransState.h"
#include "ModeFactory.h"
#include "ConcreteTransportationMediator.h"
#include <algorithm>




class AirplaneMode: public TransportMode {

public:
    AirplaneMode();
    void stopdrive();
    void drive();
    void SetTransDept(TransportDept* transDept);
    void SendMessage(std::string state);
    std::string GetMessage();
    std::string getName() const override;
    ~AirplaneMode();

    
};