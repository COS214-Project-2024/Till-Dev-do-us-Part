// Concrete Creators - Modes

#include "TaxiModeFactory.h"

TransportMode* TaxiModeFactory:: createMode(){
        return new TaxiMode();
    }