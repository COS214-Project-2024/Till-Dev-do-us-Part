// Concrete Creators - Modes

#include "TaxiModeFactory.h"
#include "TaxiMode.h"

TransportMode* TaxiModeFactory:: createMode(){
        // return new TaxiMode();
        auto mode = new TaxiMode();
        modes.push_back(mode);
        return mode;
    }

