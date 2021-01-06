#include <iostream>

using namespace std;

int main() {
    int x = 0, t, n[1000];

    cin >> t;

    for (int i = 0; i < 1000; i++) {
        if (x == t-1) {
            n[i] = x;
            x = 0;
        } else {
            n[i] = x;
            x++;
        }
    }

    for (int i = 0; i < 1000; i++) {
        cout << "N[" << i << "] = " << n[i] << endl;
    }
    return 0;
}