//
// Created by Adjamilton Junior on 8/29/15.
// S = 1 + 3/2 + 5/4 + 7/8 + ... + 39/?

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float s = 1.0;

    for (int i = 3, j = 2; i <= 39; i += 2, j *= 2) {
        s += (double)i/j;
        //cout << i << "/" << j << endl;
    }

    cout << setprecision(2) << fixed;
    cout << s << endl;

    return 0;
}

