// Concrete Creators - Modes

#include "BusModeFactory.h"
#include "BusMode.h"


TransportMode* BusModeFactory:: createMode(){
        return new BusMode();
    }
