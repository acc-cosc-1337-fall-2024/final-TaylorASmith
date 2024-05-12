#include <iostream>
#include <ctime>
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h" 
using namespace std;
 


int main() {
    srand(static_cast<unsigned int>(time(0))); 

    Die die1, die2;
    Shooter shooter(die1, die2);
    Roll* roll = shooter.throw_dice();
    int rolled_value = roll -> roll_value();

    ComeOutPhase come_out_phase;
    RollOutcome outcome = come_out_phase.get_outcome(roll);

    while (outcome == RollOutcome::natural || outcome == RollOutcome::craps) {
        cout << "Rolled value: " << rolled_value << ", roll again" << endl;
        delete roll;
        roll = shooter.throw_dice();
        rolled_value = roll -> roll_value();
        outcome = come_out_phase.get_outcome(roll);
    }

    cout << "Rolled value: " << rolled_value << ", start of point phase" << endl;
    cout << "Roll until " << rolled_value << " or 7 is rolled" << endl;

    int point = rolled_value;
    delete roll;
    roll = shooter.throw_dice();
    rolled_value = roll -> roll_value();

    PointPhase point_phase(point);
    outcome = point_phase.get_outcome(roll);

    while (outcome != RollOutcome::seven_out && outcome != RollOutcome::point) {
        cout << "Rolled value: " << rolled_value << ", roll again" << endl;
        delete roll;
        roll = shooter.throw_dice();
        rolled_value = roll -> roll_value();
        outcome = point_phase.get_outcome(roll);
    }

    cout << "Rolled value: " << rolled_value << ", end of point phase" << endl;
    cout << "Shooter rolled values:" << endl;
    shooter.display_rolled_values();

    delete roll;

    return 0;
}