#include <iostream>
#include <string>
#pragma once

class CitizenObserver {
public:
    virtual ~CitizenObserver() = default;
    virtual void update(const std::string& message) = 0;
};