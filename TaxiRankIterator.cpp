#include "TaxiRankIterator.h"

// Constructor
TaxiRankIterator::TaxiRankIterator(const std::list<TransportStation*>& taxis)
    : taxis(taxis), current(this->taxis.begin()) {}

bool TaxiRankIterator::hasNext() const {
    return current != taxis.end();
}

TransportStation* TaxiRankIterator::next() {
    if (hasNext()) {
        TransportStation* station = *current;
        ++current;
        return station;
    }
    return nullptr;
}

TransportStation* TaxiRankIterator::first() {
    current = taxis.begin();
    return currItem();
}

TransportStation* TaxiRankIterator::currItem() const {
    if (current != taxis.end()) {
        return *current;
    }
    return nullptr;
}
