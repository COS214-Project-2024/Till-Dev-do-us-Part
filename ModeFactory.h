// Abstract Creators
#pragma once
#include "TransportMode.h"
#include <algorithm>

class ModeFactory {
public:
    virtual ~ModeFactory();
    virtual TransportMode* createMode() = 0;  // Factory Method
    
protected:
    ModeFactory() = default;
    TransportMode* modes;
};