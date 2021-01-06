#include <iostream>

using namespace std;

int main() {
    unsigned long long int a, b, t, soma = 0;

    cin >> a >> b;

    // Usei soma de termos de uma PA pq se usar for vai estourar o limite de tempo
    t = (b - a) + 1;
    soma = (a+b) * t/2;

    cout << soma << "\n";

    return EXIT_SUCCESS;
}