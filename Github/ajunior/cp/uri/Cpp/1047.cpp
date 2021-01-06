#include <iostream>

using namespace std;

int main() {
    int startHour, startMinute, endHour, endMinute;

    cin >> startHour >> startMinute >> endHour >> endMinute;

    if (startHour == endHour) {
        if (startMinute == endMinute)
            cout << "O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)" << endl;
        else if (startMinute < endMinute)
            cout << "O JOGO DUROU 24 HORA(S) E " << (endMinute - startMinute) << " MINUTO(S)" << endl;
        else
        if (((60-startMinute) + endMinute) < 60)
            cout << "O JOGO DUROU 23 HORA(S) E " << ((60-startMinute) + endMinute) << " MINUTO(S)" << endl;
        else
            cout << "O JOGO DUROU 24 HORA(S) E " << ((60-startMinute) + endMinute) << " MINUTO(S)" << endl;
    }
    else if (startHour < endHour) {
        if (startMinute == endMinute)
            cout << "O JOGO DUROU " << (endHour - startHour) << " HORA(S) E 0 MINUTO(S)" << endl;
        else if (startMinute < endMinute)
            cout << "O JOGO DUROU " << (endHour - startHour) << " HORA(S) E "
                 << (endMinute - startMinute) << " MINUTO(S)" << endl;
        else
            if (((60-startMinute) + endMinute) < 60)
                cout << "O JOGO DUROU " << (endHour - startHour) - 1 << " HORA(S) E "
                     << ((60-startMinute) + endMinute) << " MINUTO(S)" << endl;
            else
                cout << "O JOGO DUROU " << (endHour - startHour) - 1 << " HORA(S) E "
                << ((60-startMinute) + endMinute) << " MINUTO(S)" << endl;
    }
    else {
        if (startMinute == endMinute)
            cout << "O JOGO DUROU " << ((24-startHour) + endHour) << " HORA(S) E 0 MINUTO(S)" << endl;
        else if (startMinute < endMinute)
            cout << "O JOGO DUROU " << ((24-startHour) + endHour) << " HORA(S) E "
            << (endMinute - startMinute) << " MINUTO(S)" << endl;
        else
            if (((60-startMinute) + endMinute) < 60)
                cout << "O JOGO DUROU " << ((24-startHour) + endHour) -1 << " HORA(S) E "
                     << ((60-startMinute) + endMinute) << " MINUTO(S)" << endl;
    }

    return EXIT_SUCCESS;
}