// Concrete Creators - Modes

#include "TaxiModeFactory.h"
#include "TaxiMode.h"

TransportMode* TaxiModeFactory:: createMode(){
        auto mode = new TaxiMode();
        return mode;
    }

