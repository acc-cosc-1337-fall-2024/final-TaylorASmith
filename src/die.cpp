//
#include "die.h"
#include <cstdlib>
#include <ctime>

Die::Die() {
    srand(static_cast<unsigned int>(time(0)));
}

int Die::roll() {
    return rand() % sides + 1;
}