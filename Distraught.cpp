#include "Distraught.h"

Distraught::Distraught() {
    name = "Distraught";
}

Feeling* Distraught::reaction() {
    int num = rand();
    if ((num % 2) == 0)
        return new Content();
    else
        return new Neutral();
}
