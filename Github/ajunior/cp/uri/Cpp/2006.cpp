#include <iostream>

using namespace std;

int main() {
    int t, r, count = 0;

    cin >> t;

    for (int i = 0; i < 5; ++i) {
        cin >> r;
        if (r == t) count++;
    }

    cout << count << endl;

    return EXIT_SUCCESS;
}