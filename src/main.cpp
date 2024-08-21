#include "vex.h"
#include "head.h"

using namespace vex;

// A global instance of competition
competition Competition;

const float pi = 3.1415926;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  
  // declaring instance of Odometry class
  Odometry Odometry;
  Drive Drive;
  Position position;

  position.X = 0;
  position.Y = 0;
  position.Heading = 0;

  // timer is the time at the end of the previous loop
  auto timer = std::chrono::steady_clock::now();
  std::chrono::milliseconds interval(20); // 20 milliseconds

    //for (int i =0; i<300; i++) idk why this was here
    while(true) {
      auto now = std::chrono::steady_clock::now();
      auto timerDiff = now - timer;

      if (timerDiff >= interval) {
      // code in this loop runs every 20 ms

        // store rotation sensor positions
        float rotL = odometryL.position(degrees);
        float rotR = odometryR.position(degrees);
        float rotB = odometryB.position(degrees);

        // resets rotation sensor positions
        odometryL.resetPosition();
        odometryR.resetPosition();
        odometryB.resetPosition();

        // updating x, y, and heading
        position.Heading += Odometry.headingCalc(rotL, rotR, rotB); 
        position.X += Odometry.xDisplacementCalc(rotL, rotR, rotB);
        position.Y += Odometry.yDisplacementCalc(rotL, rotR, rotB);

        // set timer to the time at the end of the loop
        timer = std::chrono::steady_clock::now();
      }
    } //DRIVING LOGIC
  
  // Drive.driveTo(&position, -20, -20);
  Drive.turnTo(&position, pi/2);
}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop

  int speed = 0, turn = 0, driveDirection = 1, leftDrive = 0, rightDrive = 0;
  bool clawToggle1 = true, clawToggle2 = true, mogoToggle = true;

  clawPiston.set(true);

  wait(5, seconds);

  clawPiston.set(false);
  while(true) {
    // Auton testing
    if(Controller1.ButtonA.pressing() && Controller1.ButtonB.pressing()) {
      autonomous();
    }

    // Drivetrain control
    speed = Controller1.Axis3.position();
    turn = 0.8*Controller1.Axis1.position();

    leftDrive = driveDirection*speed + turn;
    rightDrive = driveDirection*speed - turn;

    LeftFrontDrive.spin(forward, leftDrive, pct);
    LeftCenterDrive.spin(forward, leftDrive, pct);
    LeftRearDrive.spin(forward, leftDrive, pct);

    RightFrontDrive.spin(forward, rightDrive, pct);
    RightCenterDrive.spin(forward, rightDrive, pct);
    RightRearDrive.spin(forward, rightDrive, pct);

    // Intake motor control
    if(Controller1.ButtonR1.pressing()) {
      Intake.spin(forward, 100, pct);
    } else if (Controller1.ButtonR2.pressing()){
      Intake.spin(reverse, 100, pct);
    } else Intake.stop(); 

    // Reverse drive direction
    if(Controller1.ButtonUp.pressing()) {
      driveDirection = 1;
    } else if (Controller1.ButtonDown.pressing()){
      driveDirection = -1;
    }

    // Claw arm motor control
    if(Controller1.ButtonL1.pressing()) {
      ClawMotor.spin(forward, 50, pct);
    } else if(Controller1.ButtonL2.pressing()) {
      ClawMotor.spin(reverse, 50, pct);
    } else ClawMotor.stop(hold); 

    // Toggle for claw piston
    if(Controller1.ButtonA.pressing()) {
      clawPiston.set(clawToggle1);
      clawToggle1 = !clawToggle1;
      wait(200, msec);
    }

    // Toggle for tilting claw piston
    if(Controller1.ButtonX.pressing()) {
      clawTiltPiston.set(clawToggle2);
      clawToggle2 = !clawToggle2;
      wait(200, msec);
    }

    // Toggle for mogo piston
    if(Controller1.ButtonY.pressing()) {
      mogoPiston.set(mogoToggle);
      mogoToggle = !mogoToggle;
      wait(200, msec);
    }

    wait(20, msec); 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}