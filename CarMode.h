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


class CarMode : public TransportMode {
public:
    CarMode();
    void drive();
    void stopdrive();
        void SetTransDept(TransportDept* transDept);
    //Mediator
    void SendMessage(std::string state);
    std::string GetMessage();
    std::string getName() const override;
    
};