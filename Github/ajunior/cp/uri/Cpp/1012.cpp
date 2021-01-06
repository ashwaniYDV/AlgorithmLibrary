#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float a, b, c;

    cin >> a >> b >> c;

    cout << setprecision(3) << fixed
         << "TRIANGULO: " << (a*c)/2 << endl
         << "CIRCULO: " << 3.14159*(c*c) << endl
         << "TRAPEZIO: " << ((a+b)*c)/2 << endl
         << "QUADRADO: " << (b*b) << endl
         << "RETANGULO: " << (a*b) << endl;

    return 0;
}