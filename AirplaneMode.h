// AirplaneMode.h
#pragma once
#include "TransportMode.h"
#include "Airport.h"

class AirplaneMode : public TransportMode {
private:
    Airport* airport;

public:
    AirplaneMode();
    void operateStation() override;
    void useTransport() override;
};