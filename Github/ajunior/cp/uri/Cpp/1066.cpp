#include <iostream>

using namespace std;

int main() {
    int n, odd = 0, even = 0, pos = 0, neg = 0;

    for (int i = 0; i < 5; i++) {
        cin >> n;

        if (n % 2 == 0) even++;
        else odd++;

        if (n > 0) pos++;
        if (n < 0) neg++;
    }

    cout << even << " valor(es) par(es)\n";
    cout << odd << " valor(es) impar(es)\n";
    cout << pos << " valor(es) positivo(s)\n";
    cout << neg << " valor(es) negativo(s)\n";

    return EXIT_SUCCESS;
}