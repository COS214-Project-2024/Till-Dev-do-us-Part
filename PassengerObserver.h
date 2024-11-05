#include "CitizenObserver.h"
#include <iostream>
#include <string>


class PassengerObserver : public CitizenObserver {
private:
    std::string name;
    std::string destination;
public:
    PassengerObserver(const std::string& name, const std::string& destination) 
        : name(name), destination(destination) {}

    void update(const std::string& message) override {
        // Process schedule updates and notifications
        std::cout << "Passenger " << name << " received update: " << message << std::endl;
    }
};