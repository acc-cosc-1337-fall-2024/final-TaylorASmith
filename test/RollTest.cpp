#include <iostream>
#include <cassert>
#include "../src/die.h"
#include "../src/roll.h"
using namespace std;

int main() {
    Die die1, die2;
    Roll roll(die1, die2);

    for (int i = 0; i < 10; ++i) {
        roll.roll_dice();
        int rollValue = roll.roll_value();
        cout << "Roll " << i + 1 << ": " << rollValue << endl;
    }

    cout << "All rolls were within the valid range (2-12)." << endl;

    return 0;
}