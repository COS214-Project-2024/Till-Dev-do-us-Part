#ifndef WATER_H
#define WATER_H

#include "Resources.h"

class Water : public Resources {

public:
    Water();
    void getAvailableQuantity() ;
    std::string getName() const override;
    
};

#endif
