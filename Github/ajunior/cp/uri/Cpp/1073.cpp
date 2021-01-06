#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
    int n;

    cin >> n;

    cout << setprecision(0) << fixed;

    for (int i =1; i <= n; i++) {
        if (i % 2 == 0)
            cout << i << "^2 = " << pow(i,2) << endl;
    }

    return EXIT_SUCCESS;
}