// TrainStation.h
#pragma once
#include "TransportStation.h"
#include "TransportMode.h"
#include <list>

class TrainStation : public TransportStation {
private:
    // std::list<TransportMode*> trains;


public:
    void handlePassengers() override;
    void manageFreight() override;
    void maintain() override;
    

};