// Abstract Creators
#pragma once
#include "TransportMode.h"
#include <algorithm>

class ModeFactory {
public:
    virtual ~ModeFactory();
    virtual TransportMode* createMode(const std::string& type) = 0;  // Factory Method
    virtual void removeMode(TransportMode* mode);
    virtual std::vector<TransportMode*>& getModes();
protected:
    ModeFactory() = default;
    std::vector<TransportMode*> modes;
};