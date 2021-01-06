#include <iostream>

using namespace std;

int main() {
    int opcao, gas = 0, alc = 0, die = 0;

    while (cin >> opcao) {
        if (opcao == 1) alc++;
        else if (opcao == 2) gas++;
        else if (opcao == 3) die++;
        else if (opcao == 4) break;
    }

    cout << "MUITO OBRIGADO\n"
         << "Alcool: " << alc << endl
         << "Gasolina: " << gas << endl
         << "Diesel: " << die << endl;

    return EXIT_SUCCESS;
}