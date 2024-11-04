// TrainMode.h
#pragma once
#include "TransportMode.h"
#include "Railway.h"
#include <list>
#include <memory>
#include <string>
#include <iostream>

// class TransportStation;

class TrainMode : public TransportMode {
public:
    TrainMode();
    std::string getName() const override;
    void drive();
    void stopdrive();
        void SetTransDept(TransportDept* transDept);
    void SendMessage(std::string state);
    std::string GetMessage();
};
