#ifndef QUEUEITERATOR_H
#define QUEUEITERATOR_H

#include "TransportationIterator.h"
#include "TransportStation.h"
#include <list>
#include <queue>

class TransportStation;

class QueueIterator : public TransportationIterator {
private:
    std::queue<TransportStation*> queue;


public:
    ~QueueIterator();
    QueueIterator(TransportMode* mode);
    bool hasNext() const;
    TransportStation* next();
    TransportStation* first();
    TransportStation* currItem() const;
};

#endif 
