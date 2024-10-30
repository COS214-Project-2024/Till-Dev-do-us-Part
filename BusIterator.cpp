#include "BusIterator.h"

// Constructor initializes the list of bus stations and sets current to the beginning
BusIterator::BusIterator(const std::list<TransportStation*>& buses)
    : buses(buses), current(this->buses.begin()) {}

bool BusIterator::hasNext() const{
    // Check if the current iterator is not at the end
    return current != buses.end();
}

TransportStation* BusIterator::next() {
    // Return current element, then move to the next element
    if (hasNext()) {
        TransportStation* station = *current;
        ++current;
        return station;
    }
    return nullptr;  // Or handle the end case appropriately
}

TransportStation* BusIterator::first() {
    // Reset the iterator to the beginning of the list
    current = buses.begin();
    return currItem();
}

TransportStation* BusIterator::currItem() const {
    // Return the current item if it's valid
    if (current != buses.end()) {
        return *current;
    }
    return nullptr;  // Handle end case
}
