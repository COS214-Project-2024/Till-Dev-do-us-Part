#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"

/**
 * @brief The Caretaker class stores and retrieves a Memento, acting as the caretaker of the state.
 */
class Caretaker {
private:
    Memento* memento;  ///< Pointer to the stored Memento.

public:
    /**
     * @brief Default constructor for Caretaker.
     */
    Caretaker();

    /**
     * @brief Saves a Memento to the Caretaker.
     * @param memento A pointer to the Memento to be saved.
     */
    void saveMemento(Memento* memento);

    /**
     * @brief Retrieves the stored Memento.
     * @return A pointer to the stored Memento.
     */
    Memento* getMemento();

    /**
     * @brief Destructor for Caretaker.
     */
    ~Caretaker();
};

#endif
