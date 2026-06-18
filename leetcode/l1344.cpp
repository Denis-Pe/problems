class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;
        double minDegrees = minutes * 6;
        double hourDegrees = hour * 30 + (double)minutes / 2;

/*
        cout << minDegrees << endl;
        cout << hourDegrees << endl;
*/

        double diff = minDegrees - hourDegrees;

        if (diff > 0.0) {
            if (diff > 180.0) {
                return 360.0 - diff;
            } else {
                return diff;
            }
        } else if (diff < 0.0) {
            if (diff < -180.0) {
                return 360 + diff;
            } else {
                return diff * -1;
            }
        } else {
            return 0.0;
        }
    }
};
