#include <iostream>

using namespace std;

int main() {
    int n, evenCount, soma;

    while (cin >> n) {

        if (n == 0) break;

        evenCount = 0;

        while (evenCount <= 4) {
            if (n % 2 == 0) {
                evenCount++;
                soma += n;
                n += 2;
            }
            else n += 1;
        }

        cout << soma << endl;

        soma = 0;
    }

    return 0;
}

