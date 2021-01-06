#include <iostream>

using namespace std;

int main() {
    double n;

    cin >> n;

    if (n < 0.0 || n > 100.0) { cout << "Fora de intervalo\n"; }
    else if (n >= 0.0 && n <= 25.0) { cout << "Intervalo [0,25]\n"; }
    else if (n > 25.0 && n <= 50.0) { cout << "Intervalo (25,50]\n"; }
    else if (n > 50.0 && n <= 75.0) { cout << "Intervalo (50,75]\n"; }
    else { cout << "Intervalo (75,100]\n"; }

    return EXIT_SUCCESS;
}