// TaxiMode.h
#pragma once
#include "TransportMode.h"
#include "Road.h"
#include "TaxiRank.h"
#include <list>
#include <vector>
#include <memory>
#include <string>
#include <iostream>

// class TransportStation;

class TaxiMode : public TransportMode{
public:
    TaxiMode();
    void drive();
    void stopdrive();
    void SetTransDept(TransportDept* transDept);
    //Mediator
    std::string getName() const override;
    void SendMessage(std::string state);
    std::string GetMessage();
};