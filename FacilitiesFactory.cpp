#include "FacilitiesFactory.h"

FacilitiesFactory::~FacilitiesFactory() {
    delete facilities;
    facilities = nullptr;;
}
