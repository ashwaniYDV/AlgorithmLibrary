#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float salario;

    cin >> salario;

    cout << setprecision(2) << fixed;

    if (salario <= 400.0) {
        cout << "Novo salario: " << salario + (salario * 0.15) << endl;
        cout << "Reajuste ganho: " << salario * 0.15 << endl;
        cout << "Em percentual: 15 %\n";
    } else if (salario <= 800.0) {
        cout << "Novo salario: " << salario + (salario * 0.12) << endl;
        cout << "Reajuste ganho: " << salario * 0.12 << endl;
        cout << "Em percentual: 12 %\n";
    } else if (salario <= 1200.0) {
        cout << "Novo salario: " << salario + (salario * 0.10) << endl;
        cout << "Reajuste ganho: " << salario * 0.10 << endl;
        cout << "Em percentual: 10 %\n";
    } else if (salario <= 2000.0) {
        cout << "Novo salario: " << salario + (salario * 0.07) << endl;
        cout << "Reajuste ganho: " << salario * 0.07 << endl;
        cout << "Em percentual: 7 %\n";
    } else { // maior que 2.000
        cout << "Novo salario: " << salario + (salario * 0.04) << endl;
        cout << "Reajuste ganho: " << salario * 0.04 << endl;
        cout << "Em percentual: 4 %\n";
    }

    return EXIT_SUCCESS;
}