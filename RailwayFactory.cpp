// Concrete Creators - Facilities
#include "RailwayFactory.h"
#include "Railway.h"
TransportFacilities* RailwayFactory:: createFacilities() {
        // return new Railway();
        auto facility = new Railway();
        facilities.push_back(facility);
        return facility;
    }

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