#include "vex.h"
#ifndef ODOMETRY_H
#define ODOMETRY_H

struct Position {
    int Y;
    int X;
    float Heading;
};

class Odometry {
public:
    float headingCalc(float rotL, float rotR, float rotB);
    float xDisplacementCalc(float rotL, float rotR, float rotB);
    float yDisplacementCalc(float rotL, float rotR, float rotB);

    const float pi = 3.14159265359;
    const float lToCentre = 6.6875;
    const float rToCentre = 6.0;
    const float bToCentre = 10.75;
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
    void turnTo(Position *position, float finalHeading);
    void driveTo(Position *position, int x, int y);
};

#endif // DRIVE_H