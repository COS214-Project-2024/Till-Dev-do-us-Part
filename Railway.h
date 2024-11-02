// Railway.h
#pragma once
#include "TransportFacilities.h"
#include <vector>

class Railway : public TransportFacilities {
private:
    // int trainsCount;
    std::vector<TransportMode*> trains;

public:
    // Railway(TransState* state);
    Railway();
    ~Railway();
    void maintain() override;
    void setState(TransState* newState);

};