#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const double PI = 3.14159;
    int r;

    cin >> r;
    cout << setprecision(3) << fixed;
    cout << "VOLUME = " << (4.0/3) * PI * pow(r,3) << endl;

    return EXIT_SUCCESS;
}