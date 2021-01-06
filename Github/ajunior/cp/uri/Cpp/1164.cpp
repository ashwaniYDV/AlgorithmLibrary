#include <iostream>

using namespace std;

int main() {
    int n, x, soma = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        for (int j = 1; j < x; j++) {
            if (x % j == 0) soma += j;
        }
        if (soma == x) cout << x << " eh perfeito\n";
        else cout << x << " nao eh perfeito\n";
        soma = 0;
    }
    return 0;
}