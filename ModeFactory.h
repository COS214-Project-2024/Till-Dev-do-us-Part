// Abstract Creators
#pragma once
#include "TransportMode.h"
class ModeFactory {
public:
    virtual ~ModeFactory() = default;
    virtual TransportMode* createMode() = 0;  // Factory Method
    virtual void removeMode(TransportMode* mode);
    virtual std::vector<TransportMode*>& getModes();
protected:
    ModeFactory() = default;
    std::vector<TransportMode*> modes;
};