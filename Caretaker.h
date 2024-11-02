#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"

class Caretaker {
private:
    Memento* memento;

public:
    void saveMemento(Memento* memento);
    Memento* getMemento();
    ~Caretaker();
    
};

#endif 
