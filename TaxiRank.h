// TaxiRank.h
#pragma once
#include "TransportStation.h"
#include "TransportMode.h"

#include <list>
#include <string>
#include <iostream>

class TaxiRank : public TransportStation {

private:
    std::list<TransportMode*> taxis;

public:
    void handlePassengers() override;
    void manageFreight() override;
    void maintain() override;
    void addTaxi(TransportMode* taxi);
};

// class TaxiRank : public TransportStation {
// private:
//     std::list<TransportMode*> taxis;
//     int capacity;
//     bool isOccupied;

// public:
//     TaxiRank() : capacity(10), isOccupied(false) {}
    
//     void maintain() {
//         handlePassengers();
//         manageFreight();
//         // Maintain taxi rank facilities
//         std::cout << "Maintaining taxi rank facilities" << std::endl;
//         std::cout << "Checking taxi bays" << std::endl;
//         std::cout << "Updating information displays" << std::endl;
//     }

//     void addTaxi(TransportMode* taxi) {
//         if (taxis.size() < capacity) {
//             taxis.push_back(taxi);
//             isOccupied = true;
//         }
//     }

//     void removeTaxi(TransportMode* taxi) {
//         taxis.remove(taxi);
//         if (taxis.empty()) {
//             isOccupied = false;
//         }
//     }

//     bool isFull() const {
//         return taxis.size() >= capacity;
//     }
// };
