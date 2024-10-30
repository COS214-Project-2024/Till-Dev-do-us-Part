#include "FacilitiesFactory.h"

FacilitiesFactory::~FacilitiesFactory() {
    for (auto facility : facilities) {
        delete facility;
    }
    facilities.clear();
}

void FacilitiesFactory::removeFacility(TransportFacilities* facility) {
    auto it = std::find(facilities.begin(), facilities.end(), facility);
    if (it != facilities.end()) {
        delete *it;
        facilities.erase(it);
    }
}

std::vector<TransportFacilities*>& FacilitiesFactory::getFacilities() {
    return facilities;
}