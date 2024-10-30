#ifndef TRAINSTATIONITERATOR_H
#define TRAINSTATIONITERATOR_H

#include "TransportationIterator.h"
#include "TransportStation.h"
#include <list>

class TransportStation;

class TrainStationIterator : public TransportationIterator {
private:
    std::list<TransportStation*>::iterator current;
    std::list<TransportStation*> trains;

public:
    TrainStationIterator(const std::list<TransportStation*>& trains);

    bool hasNext() const override;
    TransportStation* next() override;
    TransportStation* first() override;
    TransportStation* currItem() const override;
};

#endif // TRAINSTATIONITERATOR_H
