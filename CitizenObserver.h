#include <iostream>
#include <string>

class CitizenObserver {
public:
    virtual ~CitizenObserver() = default;
    virtual void update(const std::string& message) = 0;
};