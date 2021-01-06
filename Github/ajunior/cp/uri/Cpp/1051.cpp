#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float salario, taxa = 0.0;

    cin >> salario;

    cout << setprecision(2) << fixed;

    if (salario <= 2000.0) {
        cout << "Isento\n";
    }
    else if (salario <= 3000) {
        taxa = (salario-2000.0)*0.08;
        cout << "R$ " << taxa << endl;
    }
    else if (salario <= 4500) {
        taxa = (salario-3000.0)*0.18;
        salario -= (salario-3000);
        taxa += (salario-2000.0)*0.08;
        cout << "R$ " << taxa << endl;
    }
    else {
        taxa = (salario-4500.0)*0.28;
        salario -= (salario-4500.0);
        taxa += (salario-3000.0)*0.18;
        salario -= (salario-3000);
        taxa += (salario-2000.0)*0.08;
        cout << "R$ " << taxa << endl;
    }

    return 0;
}