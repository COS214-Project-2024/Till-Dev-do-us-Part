// TrainMode.h
#pragma once
#include "TransportMode.h"
#include "Railway.h"
#include <string>
#include <iostream>

class TrainMode : public TransportMode {
private:
    Railway* railway;

public:
    TrainMode();
    TrainMode(Railway* railway, const std::string& name, double speed, double capacity);
    void operateStation() override;
    void useTransport() override;
     ~TrainMode(); // Destructor to handle removal from railway
};
