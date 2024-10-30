#ifndef TAXIRANKITERATOR_H
#define TAXIRANKITERATOR_H

#include "TransportationIterator.h"
#include "TransportStation.h"
#include <list>

class TaxiRankIterator : public TransportationIterator {
private:
    std::list<TransportStation*>::iterator current;
    std::list<TransportStation*> taxis;

public:
    TaxiRankIterator(const std::list<TransportStation*>& taxis);

    bool hasNext() const override;  // const specified
    TransportStation* next() override;
    TransportStation* first() override;
    TransportStation* currItem() const override;
};

#endif // TAXIRANKITERATOR_H
