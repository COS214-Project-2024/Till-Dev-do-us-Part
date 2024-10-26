#include "Caretaker.h"

void Caretaker::saveMemento(const Memento& memento) {
    this->memento = memento;
}

Memento Caretaker::getMemento() const {
    return memento;
}
