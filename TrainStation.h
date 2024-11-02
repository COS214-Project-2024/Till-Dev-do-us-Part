// TrainStation.h
#pragma once
#include "TransportStation.h"
#include "TransportMode.h"
#include <list>
#include <algorithm>

class TrainStation : public TransportStation {
public:
    void handlePassengers() override;
    void manageFreight() override;
    void maintain() override;
    

};