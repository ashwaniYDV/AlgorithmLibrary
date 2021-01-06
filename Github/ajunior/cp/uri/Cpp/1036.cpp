#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c, delta, r1, r2;
    cin >> a >> b >> c;

    if (a == 0) cout << "Impossivel calcular\n";
    else {
        delta = (pow(b, 2) - (4 * a * c));
        if (delta < 0) cout << "Impossivel calcular\n";
        else {
            r1 = (-b + sqrt(delta)) / (2 * a);
            r2 = (-b - sqrt(delta)) / (2 * a);

            cout << setprecision(5) << fixed;
            cout << "R1 = " << r1 << endl;
            cout << "R2 = " << r2 << endl;
        }
    }

    return EXIT_SUCCESS;
}

