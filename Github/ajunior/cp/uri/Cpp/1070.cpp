#include <iostream>

using namespace std;

int main() {
    int x, odd = 0;

    cin >> x;

    while (odd < 6) {
        if (x % 2 != 0) {
            cout << x << endl;
            odd++;
        }
        x++;
    }

    return EXIT_SUCCESS;
}