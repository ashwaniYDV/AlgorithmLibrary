#include <iostream>

using namespace std;

int main() {
    int x;

    cin >> x;

    for (int i = 0; i <= x; i++) {
        if (i > 0) {
            if (i == x) cout << "Ho!\n";
            else cout << "Ho ";
        }
    }

    return 0;
}