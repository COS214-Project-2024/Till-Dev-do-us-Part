#ifndef BUSITERATOR_H
#define BUSITERATOR_H

#include "TransportationIterator.h"
#include "TransportStation.h"
#include <list>

class TransportStation;

class BusIterator : public TransportationIterator {
private:
    std::list<TransportStation*>::iterator current;
    std::list<TransportStation*> buses;


public:
    BusIterator(const std::list<TransportStation*>& busStops);

    bool hasNext() const override;
    TransportStation* next() override;
    TransportStation* first() override;
    TransportStation* currItem() const override;
};

#endif // BUSITERATOR_H

