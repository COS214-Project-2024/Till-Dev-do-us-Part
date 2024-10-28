#include "Caretaker.h"

void Caretaker::saveMemento(Memento* memento) {
    this->memento = memento;
}

Memento* Caretaker::getMemento(){
    return memento;
}
