#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a, b, c;

    cin >> a >> b >> c;

    if (a <= b && b <= c) swap(a,c);
    if (a > b && b < c) swap(b,c);
    if (a < b && b > c) swap(a,b);
    if (a < c && c < b) {
        swap(a, b);
        swap(b, c);
    }

    if (a >= (b+c)) cout << "NAO FORMA TRIANGULO" << endl;
    else {
        if (pow(a, 2) == (pow(b, 2) + pow(c, 2))) cout << "TRIANGULO RETANGULO" << endl;
        if (pow(a, 2) > (pow(b, 2) + pow(c, 2))) cout << "TRIANGULO OBTUSANGULO" << endl;
        if (pow(a, 2) < (pow(b, 2) + pow(c, 2))) cout << "TRIANGULO ACUTANGULO" << endl;
        if (a == b && b == c) cout << "TRIANGULO EQUILATERO" << endl;
        if ((a == b && c != b) || (a == c && c != b) || (b == c && c != a)) cout << "TRIANGULO ISOSCELES" << endl;
    }

    return EXIT_SUCCESS;
}
