// Concrete Creators - Modes

#include "BusModeFactory.h"
#include "BusMode.h"


TransportMode* BusModeFactory:: createMode(){
        auto mode = new BusMode();
        return mode;    
    }

