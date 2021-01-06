#include <iostream>

using namespace std;

int main() {
    int hour = 0, minute = 0, wakeupHour = 0, wakeupMinute = 0, diff = 0;

    while (cin >> hour >> minute >> wakeupHour >> wakeupMinute) {
        if (hour == 0 && minute == 0 && wakeupHour == 0 && wakeupMinute == 0)
            break;

        if (hour == wakeupHour) {
            diff += (24 * 60);

            if (minute < wakeupMinute) {
                diff -= (24 * 60);
                diff += wakeupMinute - minute;
            } else if (minute > wakeupMinute) {
                diff += (60 - minute) + wakeupMinute;
                if (((60 - minute) + wakeupMinute) < 60)
                    diff -= 60;
            }
        } else if (hour < wakeupHour) {
            diff += (wakeupHour - hour) * 60;

            if (minute < wakeupMinute)
                diff += (wakeupMinute - minute);
            else if (minute > wakeupMinute) {
                diff += (60 - minute) + wakeupMinute;
                if (((60 - minute) + wakeupMinute) < 60)
                    diff -= 60;
            }
        } else {
            diff += ((24 - hour) + wakeupHour) * 60;

            if (minute < wakeupMinute)
                diff += (wakeupMinute - minute);
            else if (minute > wakeupMinute) {
                diff += (60 - minute) + wakeupMinute;
                if (((60 - minute) + wakeupMinute) < 60)
                    diff -= 60;
            }
        }

        cout << diff << endl;
        diff = 0;
    };

    return EXIT_SUCCESS;
}