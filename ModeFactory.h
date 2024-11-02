// Abstract Creators
#pragma once
#include "TransportMode.h"
#include <algorithm>

class ModeFactory {
public:
    // virtual ~ModeFactory();
    virtual TransportMode* createMode(const std::string& type) = 0;  // Factory Method
    // virtual void removeMode(TransportMode* mode);
protected:
    ModeFactory() = default;
    TransportMode* modes;

    // std::vector<TransportMode*> modes;
};