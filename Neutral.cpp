#include "Neutral.h"

Neutral::Neutral() {
    name = "Neutral";
}

Feeling* Neutral::reaction() {
    int num = rand();
    if ((num % 2) == 0)
        return new Content();
    else
        return new Distraught();
}
