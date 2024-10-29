// BusMode.h
#pragma once
#include "TransportMode.h"
#include "TransState.h"
#include "Road.h"
#include <string>


class BusMode : public TransportMode {
private:
    Road* road;

public:
    BusMode();
    void operateStation();
    void useTransport();
};