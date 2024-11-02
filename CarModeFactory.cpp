#include "CarModeFactory.h"
#include "CarMode.h"

TransportMode* CarModeFactory:: createMode(){
        auto mode = new CarMode();
        return mode;    
    }

