#include "Caretaker.h"

void Caretaker::saveMemento(Memento* memento) {
    this->memento = memento;
}

Memento* Caretaker::getMemento(){
    return memento;
}
Caretaker:: ~Caretaker()
{
    if(memento!=nullptr)
    {
        delete memento;
        memento=nullptr;
    }

}
