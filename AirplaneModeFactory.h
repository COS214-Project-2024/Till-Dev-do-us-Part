// Concrete Creators - Modes
#include "StationFactory.h"
#include "ModeFactory.h"
#include <vector>

class AirplaneModeFactory : public ModeFactory {
public:
    TransportMode* createMode();

};