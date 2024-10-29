#include "ProductionUtility.h"

ProductionUtility::ProductionUtility(std::string name, ResourceDepartment* resDept, Resources* resource, int workers, float capacity)
    : Utility(name, resDept, resource, workers), productionCapacity(capacity), currentProduction(0), proState(nullptr) {}

ProductionUtility::~ProductionUtility() = default;

void ProductionUtility::startProduction() {
    if (proState) {
        proState->startProduction(this);
    } else {
        std::cout << "No production state set." << std::endl;
    }
}

void ProductionUtility::processRequest() {
    std::cout << "Processing production request..." << std::endl;
    // Logic to process production request
}

float ProductionUtility::getProductionCap() const { return productionCapacity; }
void ProductionUtility::setProductionCap(float capacity) { productionCapacity = capacity; }

float ProductionUtility::getCurrentProduction() const { return currentProduction; }
void ProductionUtility::setCurrentProduction(float production) { currentProduction = production; }

std::string ProductionUtility::getProState() const {
    return (proState) ? proState->getStateName() : "No state";
}

void ProductionUtility::setProState(ProductionState* state) {
    proState = state;
}
