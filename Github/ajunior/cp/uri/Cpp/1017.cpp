#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int horas, velocidade;
    double gasolina;
    cin >> horas >> velocidade;

    gasolina = (horas*velocidade) / 12.0;

    cout << setprecision(3) << fixed;
    cout << gasolina << endl;
    return EXIT_SUCCESS;
}
