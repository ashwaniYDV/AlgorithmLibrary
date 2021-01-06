#include <iostream>

using namespace std;

int main() {
    int x;

    while (cin >> x) {
        if (x > 0) cout << "vai ter duas!\n";
        else cout << "vai ter copa!\n";
    }

    return 0;
}