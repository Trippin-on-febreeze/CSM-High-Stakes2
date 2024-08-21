#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftFrontDrive = motor(PORT1, ratio6_1, true);
motor RightFrontDrive = motor(PORT2, ratio6_1, false);
motor LeftCenterDrive = motor(PORT3, ratio6_1, true);
motor RightCenterDrive = motor(PORT4, ratio6_1, false);
motor LeftRearDrive = motor(PORT5, ratio6_1, true);
motor RightRearDrive = motor(PORT6, ratio6_1, false);
digital_out clawTiltPiston = digital_out(Brain.ThreeWirePort.E);
digital_out clawPiston = digital_out(Brain.ThreeWirePort.D);
digital_out mogoPiston = digital_out(Brain.ThreeWirePort.C);
controller Controller1 = controller(primary);
motor Intake = motor(PORT7, ratio18_1, false);
motor ClawMotor = motor(PORT8, ratio18_1, true);
rotation odometryL = rotation(PORT9, false);
rotation odometryR = rotation(PORT10, true);
rotation odometryB = rotation(PORT11, false);

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