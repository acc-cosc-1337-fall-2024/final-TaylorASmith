//
#ifndef SHOOTER_H
#define SHOOTER_H

#include "roll.h"
#include <vector>

class Shooter {
public:
    Shooter(Die& die1, Die& die2);
    Roll* throw_dice();
    void display_rolled_values() const;
    ~Shooter();

private:
    Die& die1;
    Die& die2;
    std::vector<Roll*> rolls;
};

#endif // SHOOTER_H