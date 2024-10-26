#include "Policy.h"

Policy::Policy(const std::string& name, const std::string& code)
    : name(name), code(code) {}

Memento Policy::createMemento() {
    return Memento();
}

void Policy::setMemento(const Memento& memento) {
    this->memento = memento;
}

std::string Policy:: getName()
{
    return name;
}
