// Concrete Creators - Modes

#include "TrainModeFactory.h"
#include "TrainMode.h"

TransportMode* TrainModeFactory:: createMode(){
        auto mode = new TrainMode();
        return mode;
    }
