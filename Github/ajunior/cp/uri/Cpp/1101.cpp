#include <iostream>

using namespace std;

int main() {
    int x, y, tmp, sum = 0;

    cin >> x >> y;

    while (x > 0 && y > 0) {
        if (x > y) {
            tmp = x;
            x = y;
            y = tmp;
        }

        for (; x <= y; x++) {
            cout << x << " ";
            sum += x;
        }
        cout << "Sum=" << sum << endl;
        sum = 0;
        cin >> x >> y;
    }

    return 0;
}