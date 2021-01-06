#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long double x;

    cin >> x;

    //printf("%.4LE",x);
    if (x == 0.0) cout << "+0.0000E+00\n";
    else if (x == -0.0) cout << "-0.0000E+00\n";
    else cout << setprecision(4) << uppercase << scientific << x << endl;

    return EXIT_SUCCESS;
}
