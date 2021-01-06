#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char op;
    float a[12][12], resultado = 0;

    cin >> op;

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            cin >> a[i][j];

    int x = 11, cont = 0;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < x; j++) {
            resultado += a[i][j];
            cont++;
        }
        x--;
    }

    cout << setprecision(1) << fixed;

    if (op == 'M') {
        cout << resultado/cont << endl;
    }
    else
        cout << resultado << endl;

    return 0;
}