#include "ServiceUtility.h"

ServiceUtility::ServiceUtility(std::string name, ResourceDepartment* resDept, Resources* resource, int workers, float capacity)
    : Utility(name, resDept, resource, workers), serviceCapacity(capacity), currentServiceLevel(0), servState(nullptr) {}

ServiceUtility::~ServiceUtility() = default;

void ServiceUtility::startService() {
    if (servState) {
        servState->startService(this);
    } else {
        std::cout << "No service state set." << std::endl;
    }
}

void ServiceUtility::processRequest() {
    std::cout << "Processing service request..." << std::endl;
    // Logic to process service request
}

float ServiceUtility::getServiceCap() const { return serviceCapacity; }
void ServiceUtility::setServiceCap(float capacity) { serviceCapacity = capacity; }

float ServiceUtility::getCurrentServiceLevel() const { return currentServiceLevel; }
void ServiceUtility::setCurrentServiceLevel(float level) { currentServiceLevel = level; }

std::string ServiceUtility::getServState() const {
    return (servState) ? servState->getStateName() : "No state";
}

void ServiceUtility::setServState(ServiceState* state) {
    servState = state;
}
