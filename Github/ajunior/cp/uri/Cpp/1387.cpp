#include <iostream>

using namespace std;

int main() {
    int l, r;

    do {
        cin >> l >> r;

        if (l == 0 && r == 0) break;
        else cout << (l+r) << endl;

    } while(l != 0 && r != 0);

    return EXIT_SUCCESS;
}
