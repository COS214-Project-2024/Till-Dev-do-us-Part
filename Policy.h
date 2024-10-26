#ifndef POLICY_H
#define POLICY_H

#include <string>
#include <vector>
#include "Memento.h"

class Policy {
private:
    std::string name;
    std::string code;
    Memento memento;

public:
    Policy(const std::string& name, const std::string& code);
    Memento createMemento();
    void setMemento(const Memento& memento);
    std:: string getName();
};

#endif 