// Concrete Creators - Modes

#include "TrainModeFactory.h"

TransportMode* TrainModeFactory:: createMode(){
        return new TrainMode();
    }