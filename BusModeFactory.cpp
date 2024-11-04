// Concrete Creators - Modes

#include "BusModeFactory.h"
#include "BusMode.h"

BusModeFactory:: BusModeFactory(){
    std::cout <<"Busmode fac created" <<std::endl;
}

TransportMode* BusModeFactory:: createMode(){
    std::cout <<"Busmode create Mode" <<std::endl;
        auto mode = new BusMode();
        return mode;    
    }

