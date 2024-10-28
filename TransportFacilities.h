// Abstract Products
// TransportFacilities.h
#pragma once
#include <string>
#include <vector>
#include "TransportMode.h"

class TransportFacilities {
protected:
    TransState state;

public:
    virtual ~TransportFacilities() = default;
    virtual void maintain() = 0;
    virtual void useTransport() = 0;
};