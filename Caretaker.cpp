#include "Caretaker.h"
#include <iostream>

/**
 * @brief Default constructor for Caretaker, initializes memento to nullptr.
 */
Caretaker::Caretaker() : memento(nullptr) {}

/**
 * @brief Saves a Memento to the Caretaker.
 * @param memento A pointer to the Memento to be saved.
 */
void Caretaker::saveMemento(Memento* memento) {
    this->memento = memento;
}

/**
 * @brief Retrieves the stored Memento.
 * @return A pointer to the stored Memento.
 */
Memento* Caretaker::getMemento() {
    return memento;
}

/**
 * @brief Destructor for Caretaker. Cleans up the stored Memento if it exists.
 */
Caretaker::~Caretaker() {
    if (memento != nullptr) {
        memento = nullptr;  // Set to nullptr to avoid dangling pointer
    }
}
