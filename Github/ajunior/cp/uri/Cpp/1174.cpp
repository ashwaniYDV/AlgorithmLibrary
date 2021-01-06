#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float a[100], tmp;

    for (int i = 0; i < 100; i++) {
        cin >> a[i];
    }

    cout << setprecision(1) << fixed;
    for (int i = 0; i < 100; i++) {
        if (a[i] <= 10.0)
            cout << "A[" << i << "] = " << a[i] << endl;
    }

    return 0;
}

