//
#include <iostream>
#include <cassert>
#include "../src/die.h"
#include "../src/roll.h"
#include "../src/shooter.h"
using namespace std;

int main() {
    Die die1, die2;
    Shooter shooter(die1, die2);

    for (int i = 0; i < 10; ++i) {
        Roll* roll = shooter.throw_dice();
        int rollValue = roll -> roll_value();
        cout << "Roll " << i + 1 << ": " << rollValue << endl;
        assert(rollValue >= 2 && rollValue <= 12);
    }

    cout << "All rolls were within the valid range (2-12)." << endl;

    shooter.display_rolled_values();

    return 0;
}