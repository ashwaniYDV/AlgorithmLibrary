#include <iostream>

using namespace std;

int main() {
    int n, x;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;

        if (x == 0) {
            cout << "NULL\n";
        }
        else if (x % 2 == 0) {
            if (x < 0) cout << "EVEN NEGATIVE\n";
            else cout << "EVEN POSITIVE\n";
        }
        else {
            if (x < 0) cout << "ODD NEGATIVE\n";
            else cout << "ODD POSITIVE\n";
        }
    }

    return EXIT_SUCCESS;
}
