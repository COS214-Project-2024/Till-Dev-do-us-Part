#ifndef TRANSPORTATIONMEDIATOR_H
#define TRANSPORTATIONMEDIATOR_H

#include <string>
#include <vector>

class TransportMode; // Forward declaration

class TransportationMediator {
public:
    virtual void notify(TransportMode* mode) = 0;
    virtual ~TransportationMediator() = default;
};

#endif // TRANSPORTATIONMEDIATOR_H