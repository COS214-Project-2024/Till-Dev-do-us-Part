// Concrete Creators - Modes

#include "AirplaneModeFactory.h"
#include "AirplaneMode.h"


TransportMode* AirplaneModeFactory:: createMode(){
        // return new BusMode();
        auto mode = new AirplaneMode();
        // modes.push_back(mode);
        return mode;    
    }

