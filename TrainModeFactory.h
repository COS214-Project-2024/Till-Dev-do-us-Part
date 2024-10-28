// Concrete Creators - Modes
#include "StationFactory.h"
#include "ModeFactory.h"

class TrainModeFactory : public ModeFactory {
public:
    TransportMode* createMode();
};