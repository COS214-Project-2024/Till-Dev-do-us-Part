// TaxiRank.h
#pragma once
#include "TransportStation.h"
#include "TransportMode.h"

#include <list>
#include <string>
#include <iostream>

class TaxiRank : public TransportStation {
public:
    void handlePassengers() override;
    void manageFreight() override;
    void maintain() override;
};

