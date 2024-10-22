#ifndef UTILITYSTATE_H
#define UTILITYSTATE_H

#include <iostream>
#include "Utility.h"

class Utility;

class UtilityState
{
public:
    virtual ~UtilityState() = default;

    virtual void startProduction(Utility *utility) = 0;

    virtual std::string getStateName() = 0;
};

#endif
