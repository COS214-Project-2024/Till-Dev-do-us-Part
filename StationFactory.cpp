#include "StationFactory.h"

StationFactory::~StationFactory() {
    delete stations;
    stations = nullptr;

}
