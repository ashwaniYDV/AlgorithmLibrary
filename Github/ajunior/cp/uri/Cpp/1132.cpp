#include <iostream>

using namespace std;

int main() {
    int x, y, tmp, soma = 0;

    cin >> x >> y;

    if (x > y) {
        tmp = x;
        x = y;
        y = tmp;
    }

    for (; x <= y; x++) {
        if (x % 13 != 0)
            soma += x;
    }

    cout << soma << endl;

    return EXIT_SUCCESS;
}