#include "TrainStationIterator.h"
#include "TransportStation.h"

TrainStationIterator::TrainStationIterator(const std::vector<TransportStation*>& stations) 
    : trains(stations), current(0) {}

bool TrainStationIterator::hasNext() const {
    return current < trains.size();
}

TransportStation* TrainStationIterator::next() {
    return hasNext() ? trains[current++] : nullptr;
}

TransportStation* TrainStationIterator::first() {
    current = 0;
    return trains.empty() ? nullptr : trains[0];
}

TransportStation* TrainStationIterator::currItem() const {
    return (current < trains.size() && current >= 0) ? trains[current] : nullptr;
}
