#ifndef TAXIRANKITERATOR_H
#define TAXIRANKITERATOR_H

#include "TransportationIterator.h"
#include <vector>

class TransportStation;

class TaxiRankIterator : public TransportationIterator {
private:
    int current;
    const std::vector<TransportStation*>& taxis;

public:
    TaxiRankIterator(const std::vector<TransportStation*>& ranks);

    bool hasNext() const override;
    TransportStation* next() override;
    TransportStation* first() override;
    TransportStation* currItem() const override;
};

#endif // TAXIRANKITERATOR_H
