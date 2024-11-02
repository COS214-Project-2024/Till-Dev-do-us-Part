// TrainMode.h
#pragma once
#include "TransportMode.h"
#include "Railway.h"
#include "TrainStationIterator.h"
#include <list>
#include <memory>
#include <string>
#include <iostream>

class TransportFacilities;
class TransportationMediator;
class TransportStation;

class TrainMode : public TransportMode {
public:
    TrainMode();
    std::string getName() const override;
    void drive();
    void stopdrive();
    void SendMessage(const std::string& state);
    std::string GetMessage();
};
