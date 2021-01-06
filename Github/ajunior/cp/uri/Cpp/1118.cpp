#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int valido, pergunta;
    double x, soma;

    do {
        soma = 0.0;
        valido = 0;

        while (valido < 2) {
            cin >> x;
            if (x >= 0.0 && x <= 10.0) {
                valido++;
                soma += x;
            }
            else cout << "nota invalida\n";
        }

        cout << setprecision(2) << fixed;
        cout << "media = " << soma / 2.0 << endl;

        do {
            cout << "novo calculo (1-sim 2-nao)\n";
            cin >> pergunta;
        } while(pergunta < 1 || pergunta > 2);
    } while (pergunta == 1);

    return 0;
}