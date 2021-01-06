#include <iostream>

using namespace std;

int main() {
    int n, x, y, oddCount = 0, soma;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        while (oddCount < y) {
            if (x % 2 != 0) {
                oddCount++;
                soma += x;
                x += 2;
            }
            else x += 1;
        }

        cout << soma << endl;
        oddCount = 0;
        soma = 0;
    }

    return 0;
}

