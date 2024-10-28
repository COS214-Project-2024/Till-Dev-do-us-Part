#include "Neutral.h"
#include "Content.h"  
#include "Distraught.h"

Feeling* Neutral::reaction() {
    int num = rand();

    if ((num % 2) == 0)
        return (Feeling*) new Content();
    else
        return (Feeling*) new Distraught();
}
