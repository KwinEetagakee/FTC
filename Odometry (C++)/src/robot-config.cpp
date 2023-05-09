#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
rotation Left = rotation(PORT5, true);
rotation Right = rotation(PORT8, true);
motor LB = motor(PORT1, ratio18_1, false);
motor LF = motor(PORT10, ratio18_1, false);
motor RB = motor(PORT11, ratio18_1, true);
motor RF = motor(PORT14, ratio18_1, true);
inertial Inertial = inertial(PORT3);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}