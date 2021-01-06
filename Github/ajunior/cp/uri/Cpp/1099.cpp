#include <iostream>

using namespace std;

int main() {
    int n, x, y, tmp, sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        if (x > y) {
            tmp = x;
            x = y;
            y = tmp;
        }

        for (int j = x+1; j < y; j++) {
            if (j % 2 != 0) sum += j;
        }
        cout << sum << endl;
        sum = 0;
    }

    return 0;
}