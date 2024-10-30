#include "TrainStationIterator.h"

// Constructor
TrainStationIterator::TrainStationIterator(const std::list<TransportStation*>& trains)
    : trains(trains), current(this->trains.begin()) {}

bool TrainStationIterator::hasNext() const {
    return current != trains.end();
}

TransportStation* TrainStationIterator::next() {
    if (hasNext()) {
        TransportStation* station = *current;
        ++current;
        return station;
    }
    return nullptr;
}

TransportStation* TrainStationIterator::first() {
    current = trains.begin();
    return currItem();
}

TransportStation* TrainStationIterator::currItem() const {
    if (current != trains.end()) {
        return *current;
    }
    return nullptr;
}
