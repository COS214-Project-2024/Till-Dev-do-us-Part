#include "TransportMode.h"
#include "CitizenObserver.h"
#include <algorithm>

void TransportMode::addObserver(CitizenObserver* observer) {
    observers.push_back(observer);
}

void TransportMode::removeObserver(CitizenObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void TransportMode::notifyObservers(const std::string& message) {
    for (CitizenObserver* observer : observers) {
        observer->update(message);
    }
}
