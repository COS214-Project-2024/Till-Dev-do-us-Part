// Railway.h
#pragma once
#include "TransportFacilities.h"
#include <vector>

class Railway : public TransportFacilities {
private:
    // int trainsCount;
    std::vector<TransportMode*> trains;

public:
    Railway(TransState* state);
    ~Railway();
    void maintain() override;
    void useTransport() override;
    void addTrain(TransportMode* train);
    void removeTrain(TransportMode* train);
    void changeState();
    void setState(TransState* newState);
    int getTrainCount();

};