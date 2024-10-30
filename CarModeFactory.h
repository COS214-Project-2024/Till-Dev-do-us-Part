// Concrete Creators - Modes
#include "StationFactory.h"
#include "ModeFactory.h"
#include "TransportMode.h"
#include <vector>

class CarModeFactory : public ModeFactory {
public:
    TransportMode* createMode(const std::string& type);

};