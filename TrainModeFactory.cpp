// Concrete Creators - Modes

#include "TrainModeFactory.h"
#include "TrainMode.h"

TransportMode* TrainModeFactory:: createMode(){
        // return new TrainMode();
        auto mode = new TrainMode();
        // modes.push_back(mode);
        return mode;
    }
