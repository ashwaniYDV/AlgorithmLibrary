#include <iostream>

using namespace std;

int main() {
    int n, pos, menor = sizeof(int);

    cin >> n;

    int array[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];

        if (array[i] < menor) {
            menor = array[i];
            pos = i;
        }
    }

    cout << "Menor valor: " << menor << endl;
    cout << "Posicao: " << pos << endl;

    return EXIT_SUCCESS;
}