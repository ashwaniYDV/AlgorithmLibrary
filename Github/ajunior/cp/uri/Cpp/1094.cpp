#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, x, total = 0, coelhos = 0, ratos = 0, sapos = 0;
    float percentual, valor;
    char tipo;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> tipo;

        if (tipo == 'C') {
            coelhos += x;
            total += x;
        }
        else if (tipo == 'R') {
            ratos += x;
            total += x;
        }
        else {
            sapos += x;
            total += x;
        }
    }

    cout << setprecision(2) << fixed;

    cout << "Total: " << total << " cobaias\n"
         << "Total de coelhos: " << coelhos << endl
         << "Total de ratos: " << ratos << endl
         << "Total de sapos: " << sapos << endl;

    valor = (float)coelhos*100;
    percentual = valor/total;
    cout << "Percentual de coelhos: " << percentual << " %\n";

    valor = (float)ratos*100;
    percentual = valor/total;
    cout << "Percentual de ratos: " << percentual << " %\n";

    valor = (float)sapos*100;
    percentual = valor/total;
    cout << "Percentual de sapos: " << percentual << " %\n";

    return 0;
}