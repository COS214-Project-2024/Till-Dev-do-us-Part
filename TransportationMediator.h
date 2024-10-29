#ifndef TRANSPORTATIONMEDIATOR_H
#define TRANSPORTATIONMEDIATOR_H

#include <string>
#include <vector>

class TransportMode; // Forward declaration

class TransportationMediator {
public:
    virtual void notify(TransportMode* mode, const std::string& state) = 0;
    // virtual void registerMode(TransportMode* mode) = 0;
    // virtual void manageTraffic() = 0;
    virtual ~TransportationMediator() = default;
};

#endif // TRANSPORTATIONMEDIATOR_H