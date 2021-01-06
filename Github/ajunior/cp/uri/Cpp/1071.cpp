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

    for (int i = x+1; i < y; i++) {
        if (i % 2 != 0) soma += i;
    }

    cout << soma << endl;

    return 0;
}