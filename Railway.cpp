#include "Railway.h"
#include "EmptyState.h"
#include "NormalState.h"
#include "CongestedState.h"
#include <iostream>
#include <string>
#include <algorithm>

Railway::Railway(TransState* state) : TransportFacilities(state) {}

Railway::~Railway() {
    delete currentState;
}

void Railway::addTrain(TransportMode* train) {
    trains.push_back(train);
    changeState();  // Reevaluate state whenever a train is added
}

void Railway::removeTrain(TransportMode* train) {
    auto it = std::find(trains.begin(), trains.end(), train);
    if (it != trains.end()) {
        trains.erase(it);
        changeState();  // Reevaluate state whenever a train is removed
    }
}

void Railway::changeState() {
    if (getTrainCount() == 0) {
        setState(new EmptyState());
    } else if (getTrainCount() > 10) {
        setState(new CongestedState());
    } else {
        setState(new NormalState());
    }
    currentState->handleState(this);  // Call handleState based on the current state
}

void Railway::setState(TransState* newState) {
    if (currentState) delete currentState;
    currentState = newState;
}

int Railway::getTrainCount(){
    return trains.size();
}

// void Railway::addTrain(TransportMode* train) {
//     if (train) {
//         trains.push_back(train);
//         std::cout << "Train added to the railway. Total trains: " << getTrainsCount() << std::endl;
//     }
// }


// int Railway::getTrainsCount(){
//     return trains.size();
// }

// void Railway::removeTrain(TransportMode* train) {
//     auto it = std::find(trains.begin(), trains.end(), train);
//     if (it != trains.end()) {
//         trains.erase(it);
//         std::cout << "Train removed from the railway. Total trains: " << getTrainsCount() << std::endl;
//     }
// }


void Railway::maintain() {
    std::cout << "Performing railway maintenance" << std::endl;
   
    // Perform maintenance tasks
    std::cout << "Checking rail tracks" << std::endl;
    std::cout << "Testing signals" << std::endl;
    std::cout << "Maintaining power lines" << std::endl;
}

void Railway::useTransport() {
    std::cout << "Railway in use by trains." << std::endl;
}