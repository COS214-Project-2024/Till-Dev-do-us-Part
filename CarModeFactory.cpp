#include "CarModeFactory.h"
#include "CarMode.h"

TransportMode* CarModeFactory:: createMode(){
        // return new CarMode();
        auto mode = new CarMode();
        // modes.push_back(mode);
        return mode;    
    }

