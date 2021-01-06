#include <iostream>

using namespace std;

int main() {
    int n, x, y, m = 0, v = 0;
    string z;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> x >> z >> y;

            if (j == 0) {
                m += x;
                v += y;
            } else {
                v += x;
                m += y;
            }
        }

        if (m > v) cout << "Time 1" << endl;
        else if (v > m) cout << "Time 2" << endl;
        else cout << "Penaltis" << endl;

        m = 0;
        v = 0;
    }
    return EXIT_SUCCESS;
}