// Concrete Creators - Modes
#include "ModeFactory.h"

class TaxiModeFactory : public ModeFactory {
public:
    TransportMode* createMode();
};