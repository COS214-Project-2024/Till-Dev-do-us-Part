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
    void operateStation() override;
    void useTransport() override;
};
