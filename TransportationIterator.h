#ifndef TRANSPORTATIONITERATOR_H
#define TRANSPORTATIONITERATOR_H

#include <vector>

// Forward declaration for TransportStation
class TransportStation;

class TransportationIterator {
public:
    virtual ~TransportationIterator() = default;
    virtual bool hasNext() const = 0;
    virtual TransportStation* next() = 0;
    virtual TransportStation* first() = 0;
    virtual TransportStation* currItem() const = 0;
};

#endif // TRANSPORTATIONITERATOR_H

