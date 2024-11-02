#include "TransState.h"

TransState::~TransState(){
    delete stateFacility;  // Delete the single pointer
    stateFacility = nullptr; 
}