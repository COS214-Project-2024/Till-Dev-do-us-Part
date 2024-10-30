#include "CarModeFactory.h"
#include "CarMode.h"

TransportMode* CarModeFactory:: createMode(const std::string& type){
        // return new CarMode();
        auto mode = new CarMode();
        modes.push_back(mode);
        return mode;    
    }

