#include "Content.h"

Content::Content() {
    name = "Content";
}

Feeling* Content::reaction() {
    int num = rand();
    if ((num % 2) == 0)
        return new Neutral();
    else
        return new Distraught();
}
