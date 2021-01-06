#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int t, b;
    double x, valueDabriel, valueGuarte;
    vector<float>vet;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> b;
        for (int j = 0; j < 6; j++) {
            cin >> x;
            vet.push_back(x);
        }

        if ((int)vet[2] % 2 != 0 && (int)vet[5] % 2 != 0) {
            valueDabriel = ((vet[0] + vet[1]) / 2) + b;
            valueGuarte = ((vet[3] + vet[4]) / 2) + b;
        } else if ((int)vet[2] % 2 != 0 && (int)vet[5] % 2 == 0) {
            valueDabriel = ((vet[0] + vet[1]) / 2) + b;
            valueGuarte = ((vet[3] + vet[4]) / 2);
        } else if ((int)vet[2] % 2 == 0 && (int)vet[5] % 2 != 0) {
            valueDabriel = ((vet[0] + vet[1]) / 2);
            valueGuarte = ((vet[3] + vet[4]) / 2) + b;
        } else {
            valueDabriel = ((vet[0] + vet[1]) / 2);
            valueGuarte = ((vet[3] + vet[4]) / 2);
        }

        if (valueDabriel > valueGuarte)
            cout << "Dabriel\n";
        else if (valueDabriel < valueGuarte)
            cout << "Guarte\n";
        else
            cout << "Empate\n";

        vet.clear();
    }

    return 0;
}