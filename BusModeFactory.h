// Concrete Creators - Modes
#include "StationFactory.h"
#include "ModeFactory.h"

class BusModeFactory : public ModeFactory {
public:
    TransportMode* createMode();

};