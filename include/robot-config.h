using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftFrontDrive;
extern motor RightFrontDrive;
extern motor LeftCenterDrive;
extern motor RightCenterDrive;
extern motor LeftRearDrive;
extern motor RightRearDrive;
extern digital_out clawTiltPiston;
extern digital_out clawPiston;
extern digital_out mogoPiston;
extern controller Controller1;
extern motor Intake;
extern motor ClawMotor;
extern rotation odometryL;
extern rotation odometryR;
extern rotation odometryB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );