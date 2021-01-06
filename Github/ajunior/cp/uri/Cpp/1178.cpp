#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double y, n[100];

    cin >> y;
    n[0] = y;

    for (int i = 1; i <= 99; i++) {
        n[i] = n[i-1] / 2.0;
    }

    cout << setprecision(4) << fixed;

    for (int i = 0; i < 100; i++) {
        cout << "N[" << i << "] = " << n[i] << endl;
    }
    return 0;
}