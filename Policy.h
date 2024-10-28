#ifndef POLICY_H
#define POLICY_H

#include <string>
#include <vector>
#include "Memento.h"

class Policy {
private:
    std::string name;
    std::string code;
    Memento* memento;

public:
    Policy(std::string name, std::string code);
    
    std:: string getName();
};

#endif 