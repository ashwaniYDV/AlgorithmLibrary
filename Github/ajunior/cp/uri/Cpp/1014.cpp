#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int distancia;
    double gasolina;

    cin >> distancia >> gasolina;

    cout << setprecision(3) << fixed;
    cout << distancia/gasolina << " km/l\n";
    return EXIT_SUCCESS;
}