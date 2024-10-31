#ifndef ENERGY_H
#define ENERGY_H

#include "Resources.h"

class Energy : public Resources{

public:
    Energy();
   void getAvailableQuantity();
   std::string getName() const override;
};

#endif
