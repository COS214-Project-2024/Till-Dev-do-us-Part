// CarMode.h
#pragma once
#include "TransportMode.h"
#include "Road.h"

class CarMode : public TransportMode {
private:
    Road* road;

public:
    CarMode();
    void operateStation() override;
    void useTransport() override;
};