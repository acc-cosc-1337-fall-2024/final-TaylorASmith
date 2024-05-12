//
#include "shooter.h"
#include <iostream>

Shooter::Shooter(Die& die1, Die& die2)
    : die1(die1), die2(die2) {}

Roll* Shooter::throw_dice() {
    Roll* roll = new Roll(die1, die2);
    roll -> roll_dice();
    rolls.push_back(roll);
    return roll;
}

void Shooter::display_rolled_values() const {
    for (const Roll* roll : rolls) {
        std::cout << "Roll value: " << roll -> roll_value() << std::endl;
    }
}

Shooter::~Shooter() {
    for (Roll* roll : rolls) {
        delete roll;
    }
    rolls.clear();
}