#include <iostream>

using namespace std;

int main() {
    int a, n, soma;

    cin >> a;
    soma = a;

    do {
        cin >> n;
    } while (n <= 0);

    for (int i = a+1, j = a+(n-1); i <= j; i++) {
        soma += i;
    }

    cout << soma << endl;

    return 0;
}