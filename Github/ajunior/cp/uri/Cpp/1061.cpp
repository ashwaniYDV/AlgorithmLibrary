#include <iostream>

using namespace std;

int main() {
    int startDay, endDay, startHour, endHour, startMinute, endMinute, startSecond, endSecond;
    int days = 0, hours = 0, minutes = 0, seconds = 0;
    int startTimeInSeconds, endTimeInSeconds, differenceTimeInSeconds;
    string str;

    // Reading the start
    cin >> str >> startDay;
    cin >> startHour >> str >> startMinute >> str >> startSecond;

    // Reading the end
    cin >> str >> endDay;
    cin >> endHour >> str >> endMinute >> str >> endSecond;

    // DAYS
    if (startDay < endDay)
        days = endDay - startDay;

    // HOURS
    if (startHour < endHour)
        hours = endHour - startHour;
    else if (startHour > endHour) {
        hours = (24 - startHour)  + endHour;
        if (hours < 24 && days > 0) days--;
    }

    // MINUTES
    if (startMinute < endMinute) minutes = endMinute - startMinute;
    else if (startMinute > endMinute) {
        minutes = (60 - startMinute) + endMinute;
        if (minutes < 60 && hours > 0) hours--;
    }

    // SECONDS
    if (startSecond < endSecond) seconds = endSecond - startSecond;
    else if (startSecond > endSecond) {
        seconds = (60 - startSecond) + endSecond;
        if (seconds < 60 && minutes > 0) minutes--;
    }

    cout << days << " dia(s)" << endl;
    cout << hours << " hora(s)" << endl;
    cout << minutes << " minuto(s)" << endl;
    cout << seconds << " segundo(s)" << endl;

    return EXIT_SUCCESS;
}