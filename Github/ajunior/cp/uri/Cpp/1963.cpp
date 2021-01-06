#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b;

    cin >> a >> b;

    cout << setprecision(2) << fixed
         << (((b-a)/a)*100.0) << "%" << endl;

    return EXIT_SUCCESS;
}