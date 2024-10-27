// TrainStation.h
#pragma once
#include "TransportStation.h"

class TrainStation : public TransportStation {
public:
    void handlePassengers() override;
    void manageFreight() override;
    void maintain() override;
};