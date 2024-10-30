#include "TaxiRankIterator.h"
#include "TransportStation.h"

TaxiRankIterator::TaxiRankIterator(const std::vector<TransportStation*>& ranks) 
    : taxis(ranks), current(0) {}

bool TaxiRankIterator::hasNext() const {
    return current < taxis.size();
}

TransportStation* TaxiRankIterator::next() {
    return hasNext() ? taxis[current++] : nullptr;
}

TransportStation* TaxiRankIterator::first() {
    current = 0;
    return taxis.empty() ? nullptr : taxis[0];
}

TransportStation* TaxiRankIterator::currItem() const {
    return (current < taxis.size() && current >= 0) ? taxis[current] : nullptr;
}
