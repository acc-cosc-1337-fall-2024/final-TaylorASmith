#include <iostream>
#include <cassert>
#include "../src/die.h"
#include "../src/roll.h"
#include "../src/come_out_phase.h"
#include "../src/point_phase.h"

int main() {
    Die die1, die2;
    Roll roll(die1, die2);
    ComeOutPhase comeOutPhase;
    PointPhase pointPhase(6);

    roll.roll_dice();
    RollOutcome outcome = comeOutPhase.get_outcome(&roll);
    assert(outcome == RollOutcome::natural || outcome == RollOutcome::craps || outcome == RollOutcome::point);

    roll.roll_dice();
    outcome = pointPhase.get_outcome(&roll);
    assert(outcome == RollOutcome::point || outcome == RollOutcome::seven_out || outcome == RollOutcome::nopoint);

    std::cout << "All tests passed." << std::endl;

    return 0;
}