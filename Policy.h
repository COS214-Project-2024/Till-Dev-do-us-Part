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
    Memento* createMemento();
    void setMemento(Memento* memento);
    std:: string getName();
};

#endif 