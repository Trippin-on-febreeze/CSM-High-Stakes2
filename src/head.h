#include "vex.h"
#ifndef ODOMETRY_H
#define ODOMETRY_H

class Odometry {
public:
    Odometry();
    float headingCalc(float rotL, float rotR, float rotB);
    float xDisplacementCalc(float rotL, float rotR, float rotB);
    float yDisplacementCalc(float rotL, float rotR, float rotB);

    const float pi = 3.14159265359;
    const float lToCentre = 7.75;
    const float rToCentre = 7.25;
    const float bToCentre = 10.5;
};

#endif // ODOMETRY_H