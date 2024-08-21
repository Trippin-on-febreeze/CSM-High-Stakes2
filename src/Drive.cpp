#include "head.h"
#include "vex.h"
#include <cmath>
const float pi = 3.14159265359;



// moves the left side of the drivetrain
void Drive::moveL(int direction) {
    if (direction == 1) {
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
void Drive::moveR(int direction) {
    if (direction == 1) {
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
void Drive::driveDistance(int distance) {
    int turnDegrees = distance/1.625*2*180 / pi;
    LeftFrontDrive.spinTo(turnDegrees, degrees, false);
    LeftCenterDrive.spinTo(turnDegrees, degrees, false);
    LeftRearDrive.spinTo(turnDegrees, degrees, false);

    RightFrontDrive.spinTo(turnDegrees, degrees, false);
    RightCenterDrive.spinTo(turnDegrees, degrees, false);
    RightRearDrive.spinTo(turnDegrees, degrees, false);
}

// turns the robot, direction = 1 is right, direction != 1 is left
void Drive::turn(int direction) {
  if (direction == 1) {
        moveL(1);
        moveR(-1);
    } else {
        moveL(1);
        moveR(-1);
    }
}

// turns the robot from its current heading to a chosen heading
void Drive::turnTo(Position *position, float finalHeading) {
    while ((*position).Heading != finalHeading) {
        if((*position).Heading - (finalHeading + 2*pi) < (*position).Heading - finalHeading) {
            turn(1); //dk if this is correct, may have to switch 1 for -1
        } else {
            turn(-1);
        }

        wait(200, msec);
    }
}

// drives the robot in a straight line to point (X,Y)
void Drive::driveTo(Position *position, int x, int y) {
  float finalHeading = 0;
  float distance = 0;

  while ((*position).Heading != finalHeading) {
      finalHeading = atan(((*position).Y - y) / ((*position).X - x));
      Drive::turnTo(position, finalHeading);
  }  

  while ((*position).Y != y || (*position).X != x) {
      distance = sqrt(pow((*position).X + x, 2) + pow((*position).Y + y, 2));
      driveDistance(distance);
  }
}