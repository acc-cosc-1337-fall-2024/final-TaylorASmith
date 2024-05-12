#include <iostream>
#include "../src/die.h"
using namespace std;

int main() {
    Die die;

    for (int i = 0; i < 10; ++i) {
        int rollResult = die.roll();
        cout << "Roll " << i + 1 << ": " << rollResult << endl;
    }

    return 0;
}