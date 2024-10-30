#ifndef TRAINSTATIONITERATOR_H
#define TRAINSTATIONITERATOR_H

#include "TransportationIterator.h"
#include <vector>

class TransportStation;

class TrainStationIterator : public TransportationIterator {
private:
    int current;
    const std::vector<TransportStation*>& trains;

public:
    TrainStationIterator(const std::vector<TransportStation*>& stations);

    bool hasNext() const override;
    TransportStation* next() override;
    TransportStation* first() override;
    TransportStation* currItem() const override;
};

#endif // TRAINSTATIONITERATOR_H
