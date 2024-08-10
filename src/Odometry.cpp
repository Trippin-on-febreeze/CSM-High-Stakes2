#include "head.h"
#include <cmath> // For sin()

Odometry::Odometry() {
    // Initialization is done in member initializer list (if needed)
}

float Odometry::headingCalc(float rotL, float rotR, float rotB) {
    // Convert rotation from degrees to radians
    float arclengthL = pi / 180 * rotL; 
    float arclengthR = pi / 180 * rotR; 
    float arclengthB = pi / 180 * rotB;

    // Change in heading in radians
    float headingChange = (arclengthL - arclengthR) / (lToCentre + rToCentre);
    
    return headingChange;
}

float Odometry::yDisplacementCalc(float rotL, float rotR, float rotB) {
    // Convert rotation from degrees to radians
    float arclengthL = pi / 180 * rotL; 
    float arclengthR = pi / 180 * rotR; 
    float arclengthB = pi / 180 * rotB;

    // Calculate heading change
    float headingChange = (arclengthL - arclengthR) / (lToCentre + rToCentre);

    // Calculate y displacement
    float yChange = 2 * sin(headingChange) * (arclengthR / headingChange + rToCentre);
    
    return yChange;
}

float Odometry::xDisplacementCalc(float rotL, float rotR, float rotB) {
    // Convert rotation from degrees to radians
    float arclengthL = pi / 180 * rotL; 
    float arclengthR = pi / 180 * rotR; 
    float arclengthB = pi / 180 * rotB;

    // Calculate heading change
    float headingChange = (arclengthL - arclengthR) / (lToCentre + rToCentre);

    // Calculate x displacement
    float xChange = 2 * sin(headingChange) * (arclengthB / headingChange + bToCentre);
    
    return xChange;
}