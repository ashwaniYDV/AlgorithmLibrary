#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double n;
    int x = 0;

    cin >> n;

    cout << "NOTAS:\n";

    while(n >= 100) {
        x++;
        n -= 100.0;
    }
    cout << x << " nota(s) de R$ 100.00\n";

    x = 0;
    while(n >= 50) {
        x++;
        n -= 50.0;
    }
    cout << x << " nota(s) de R$ 50.00\n";

    x = 0;
    while(n >= 20) {
        x++;
        n -= 20.0;
    }
    cout << x << " nota(s) de R$ 20.00\n";

    x = 0;
    while(n >= 10) {
        x++;
        n -= 10.0;
    }
    cout << x << " nota(s) de R$ 10.00\n";

    x = 0;
    while(n >= 5) {
        x++;
        n -= 5.0;
    }
    cout << x << " nota(s) de R$ 5.00\n";

    x = 0;
    while(n >= 2) {
        x++;
        n -= 2.0;
    }
    cout << x << " nota(s) de R$ 2.00\n";

    x = 0;

    cout << "MOEDAS:\n";

    while(n >= 1) {
        x++;
        n -= 1.0;
    }
    cout << x << " moeda(s) de R$ 1.00\n";

    x = 0;
    while(n >= 0.5) {
        x++;
        n -= 0.50;
    }
    cout << x << " moeda(s) de R$ 0.50\n";

    x = 0;
    while(n >= 0.25) {
        x++;
        n -= 0.25;
    }
    cout << x << " moeda(s) de R$ 0.25\n";

    x = 0;
    while(n >= 0.1) {
        x++;
        n -= 0.1;
    }
    cout << x << " moeda(s) de R$ 0.10\n";

    x = 0;
    while(n >= 0.05) {
        x++;
        n -= 0.05;
    }
    cout << x << " moeda(s) de R$ 0.05\n";

    x = 0;
    while(n >= 0.01) {
        x++;
        n -= 0.01;
    }
    cout << x << " moeda(s) de R$ 0.01\n";

    return EXIT_SUCCESS;
}
