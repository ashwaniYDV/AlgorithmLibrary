#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int coluna;
    char op;
    float a[12][12], resultado = 0;

    cin >> coluna >> op;

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            cin >> a[i][j];

    for (int i = 0; i < 12; i++) {
            resultado += a[i][coluna];
    }

    cout << setprecision(1) << fixed;

    if (op == 'M') {
        cout << resultado/12 << endl;
    }
    else
        cout << resultado << endl;

    return 0;
}