#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float a, b, c;

    cin >> a >> b >> c;

    cout << setprecision(1) << fixed;

    if ( ((b-c) < a && a < (b+c)) && ((a-c) < b && b < (a+c)) && ((a-b) < c && c < (a+b)) ) {
        cout << "Perimetro = " << a + b + c << endl;
    } else {
        cout << "Area = " << ((a+b) * c)/2 << endl;
    }

    return 0;
}