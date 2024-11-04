#include "ModeFactory.h"

ModeFactory::~ModeFactory() {
    delete modes;  // Delete the single pointer
    modes = nullptr;
}
