// Concrete Creators - Modes

#include "BusModeFactory.h"
#include "BusMode.h"


TransportMode* BusModeFactory:: createMode(){
        // return new BusMode();
        auto mode = new BusMode();
        // modes.push_back(mode);
        return mode;    
    }

