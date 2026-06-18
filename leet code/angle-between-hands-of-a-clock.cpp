#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    double angleClock(int hour, int minutes) {

        double minuteAngle = minutes * 6.0; // 360/60

        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        // 360/12 = 30, and hour hand moves 0.5 deg per minute

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};