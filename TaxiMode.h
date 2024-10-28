// TaxiMode.h
#pragma once
#include "TransportMode.h"
#include "Road.h"
#include <string>
#include <list>
#include <iostream>

class TaxiMode : public TransportMode {
private:
    Road* road;

public:
    TaxiMode();
    void operateStation() override;
    void useTransport() override;
};