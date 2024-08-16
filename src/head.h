#include "vex.h"
#ifndef ODOMETRY_H
#define ODOMETRY_H

class Odometry {
public:
    float headingCalc(float rotL, float rotR, float rotB);
    float xDisplacementCalc(float rotL, float rotR, float rotB);
    float yDisplacementCalc(float rotL, float rotR, float rotB);

    const float pi = 3.14159265359;
    const float lToCentre = 7.75;
    const float rToCentre = 7.25;
    const float bToCentre = 10.5;
};

#endif // ODOMETRY_H

#ifndef DRIVE_H
#define DRIVE_H
class Drive {
public:
    void moveL(int direction);
    void moveR(int direction);
    void driveDistance(int distance);
    void turn(int direction);
    void turnTo(float heading, float finalHeading);
    void driveTo(int X, int Y, int x, int y, float heading);
};

#endif // DRIVE_H