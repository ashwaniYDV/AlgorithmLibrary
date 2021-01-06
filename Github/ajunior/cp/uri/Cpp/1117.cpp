#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int valido = 0;
    double x, soma = 0.0;

   while (valido < 2) {
       cin >> x;
       if (x >= 0.0 && x <= 10.0) {
           valido++;
           soma += x;
       }
       else cout << "nota invalida\n";
   }

   cout << setprecision(1) << fixed;
   cout << "media = " << soma / 2.0 << endl;

    return 0;
}