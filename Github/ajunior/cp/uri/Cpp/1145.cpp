#include <iostream>

using namespace std;

int main() {
    int y, x;

    cin >> x >> y;

    for (int i = 1; i <= y; i++) {
        if ((i % x == 0) || i == y) {
                cout << i << endl;
        }
        else {
            cout << i << " ";
        }
    }

    return 0;
}