#include "vex.h"
#include <cmath>
const float pi = 3.14159265359;

// moves the left side of the drivetrain
void moveL(int direction) {
    if (direction = 1) {
        LeftFrontDrive.spin(forward, 100, pct);
        LeftCenterDrive.spin(forward, 100, pct);
        LeftRearDrive.spin(forward, 100, pct);
    } else {
        LeftFrontDrive.spin(reverse, 100, pct);
        LeftCenterDrive.spin(reverse, 100, pct);
        LeftRearDrive.spin(reverse, 100, pct);
    }
}

// moves the right side of the drivetrain
void moveR(int direction) {
    if (direction = 1) {
        RightFrontDrive.spin(forward, 100, pct);
        RightCenterDrive.spin(forward, 100, pct);
        RightRearDrive.spin(forward, 100, pct);
    } else {
        RightFrontDrive.spin(reverse, 100, pct);
        RightCenterDrive.spin(reverse, 100, pct);
        RightRearDrive.spin(reverse, 100, pct);
    }
}

// drives the robot for a specified distance
void driveDistance(int distance) {
    int turnDegrees = distance/1.625*180 / pi;
    LeftFrontDrive.spinTo(turnDegrees, degrees, false);
    LeftCenterDrive.spinTo(turnDegrees, degrees, false);
    LeftRearDrive.spinTo(turnDegrees, degrees, false);

    RightFrontDrive.spinTo(turnDegrees, degrees, false);
    RightCenterDrive.spinTo(turnDegrees, degrees, false);
    RightRearDrive.spinTo(turnDegrees, degrees, false);
}

// turns the robot, direction = 1 is right, direction != 1 is left
void DriveTurn(int direction) {
  if (direction == 1) {
        moveL(1);
        moveR(-1);
    } else {
        moveL(1);
        moveR(-1);
    }
}

// turns the robot from its current heading to a chosen heading
void turnTo(float heading, int direction) {
    while (heading != direction) {
        if(heading - (direction + 2*pi) < heading - direction) {
            DriveTurn(1); //dk if this is correct, may have to switch 1 for -1
        } else {
            DriveTurn(-1);
        }
    }
}

// drives the robot in a straight line to point (X,Y)
void driveTo(int X, int Y, int x, int y, int direction) {
    // timer is the time at the end of the previous loop
  auto timer = std::chrono::steady_clock::now();
  std::chrono::milliseconds interval(20); // 20 milliseconds

    while (true) {
      auto now = std::chrono::steady_clock::now();
      auto timerDiff = now - timer;

      if (timerDiff >= interval) {
      // code in this loop runs every 10 ms
        float driveHeading = atan((Y - y) / (X - x));
        float distance = sqrt(pow(X - x, 2) + pow(Y - y, 2));
        //float distance = sqrt(pow((X - x), 2)) + pow((Y - y), 2)));

        turnTo(driveHeading, direction);
        driveDistance(distance);
        
        // set timer to the time at the end of the loop
        timer = std::chrono::steady_clock::now();
      }
    }  
}